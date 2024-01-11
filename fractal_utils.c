/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susajid <susajid@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:07:01 by susajid           #+#    #+#             */
/*   Updated: 2024/01/11 12:47:37 by susajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	set_hooks(t_display	*display);

t_display	*build_display(char *title, double x_axis_len, double y_axis_len)
{
	t_display	*result;
	int			img_width;
	int			img_height;

	result = malloc(sizeof(t_display));
	if (result)
		result->img = malloc(sizeof(t_image));
	if (!result || !result->img)
		exit_program(result, 1, NULL);
	result->mlx = mlx_init();
	if (!result->mlx)
		exit_program(result, 2, "could not establish connection to x-server\n");
	result->win = mlx_new_window(result->mlx, WIDTH, HEIGHT, title);
	if (!result->win)
		exit_program(result, 3, "could not create window to display fractal\n");
	img_width = WIDTH;
	img_height = HEIGHT;
	closest_size(&img_width, &img_height, x_axis_len, y_axis_len);
	result->img->image = mlx_new_image(result->win, img_width, img_height);
	if (!result->img->image)
		exit_program(result, 4, "could not display fractal on window\n");
	result->img->buffer = mlx_get_data_addr(result->img->image,
			&result->img->bpp, &result->img->line_length, &result->img->endian);
	set_hooks(result);
	return (result);
}

static void	set_hooks(t_display	*display)
{
	if (!display || !display->win)
		return ;
	mlx_hook(display->win, ON_DESTROY, 0, exit_hook, display);
	mlx_key_hook(display->win, key_hook, display);
	mlx_mouse_hook(display->win, mouse_hook, display);
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
