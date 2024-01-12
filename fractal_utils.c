/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susajid <susajid@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:07:01 by susajid           #+#    #+#             */
/*   Updated: 2024/01/12 15:48:11 by susajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_display	*build_display(int max_w, int max_h, char *title, t_complex limit)
{
	t_display	*res;

	closest_size(&max_w, &max_h, limit.r, limit.i);
	res = malloc(sizeof(t_display));
	if (res)
		res->img = malloc(sizeof(t_image));
	if (!res || !res->img)
		exit_program(res, 1, NULL);
	res->mlx = mlx_init();
	if (!res->mlx)
		exit_program(res, 2, "could not establish connection to x-server\n");
	res->win = mlx_new_window(res->mlx, max_w, max_h, title);
	if (!res->win)
		exit_program(res, 3, "could not create window to display fractal\n");
	res->width = max_w;
	res->height = max_h;
	res->img->image = mlx_new_image(res->win, res->width, res->height);
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

void	put_pixel(t_image *img, int x, int y, int color)
{
	char	*pixel;

	if (!img)
		return ;
	pixel = img->buffer + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int *)pixel = color;
}

unsigned int	get_color(int n_iter)
{
	return (0xFFFFFF - (n_iter * pow(16, 6) - 1) / MAX_ITERATIONS);
}
