/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susajid <susajid@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:07:01 by susajid           #+#    #+#             */
/*   Updated: 2024/01/15 10:34:02 by susajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_display	*build_display(t_pixel max_size, char *title, t_complex limit)
{
	t_display	*res;

	closest_size(&max_size.x, &max_size.y, limit.r, limit.i);
	res = malloc(sizeof(t_display));
	if (res)
		res->img = malloc(sizeof(t_image));
	if (!res || !res->img)
		exit_program(res, 1, NULL);
	res->size = max_size;
	res->mlx = mlx_init();
	if (!res->mlx)
		exit_program(res, 2, "could not establish connection to x-server\n");
	res->win = mlx_new_window(res->mlx, max_size.x, max_size.y, title);
	if (!res->win)
		exit_program(res, 3, "could not create window to display fractal\n");
	res->img->image = mlx_new_image(res->win, res->size.x, res->size.y);
	if (!res->img->image)
		exit_program(res, 4, "could not display fractal on window\n");
	res->img->buffer = mlx_get_data_addr(res->img->image,
			&res->img->bpp, &res->img->line_length, &res->img->endian);
	mlx_hook(res->win, ON_DESTROY, 0, exit_hook, res);
	mlx_key_hook(res->win, key_hook, res);
	mlx_mouse_hook(res->win, mouse_hook, res);
	return (res);
}

void	exit_program(t_display *display, int exit_code, char *msg)
{
	if (exit_code == 1 && msg == NULL)
		msg = "a memory allocation error occurred\n";
	if (msg)
		ft_printf(msg);
	if (!display)
		exit(exit_code);
	if (display->img && display->img->image && display->mlx)
		mlx_destroy_image(display->mlx, display->img->image);
	free(display->img);
	if (display->win && display->mlx)
		mlx_destroy_window(display->mlx, display->win);
	if (display->mlx)
		free(display->mlx);
	free(display);
	exit(exit_code);
}

void	put_pixel(t_image *img, t_pixel pixel, int color)
{
	char	*add;

	if (!img)
		return ;
	add = img->buffer + (pixel.y * img->line_length + pixel.x * (img->bpp / 8));
	*(unsigned int *)add = color;
}

unsigned int	get_color(int n_iter)
{
	return (0xFFFFFF - (n_iter * 0xFFFFFF) / MAX_ITERATIONS);
}
