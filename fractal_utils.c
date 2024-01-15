/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susajid <susajid@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:07:01 by susajid           #+#    #+#             */
/*   Updated: 2024/01/15 16:25:34 by susajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
	Requirement to prevent fractal distortion
	-----------------------------------------
	=>	ASPECT RATIO
	=>	width	max_x - min_x
		----- = -------------
		height	max_y - min_y
*/
t_display	*build_display(t_pixel max_size, char *title,
				t_complex min, t_complex max)
{
	t_display	*res;

	closest_size(&max_size.x, &max_size.y, max.r - min.r, max.i - min.i);
	res = malloc(sizeof(t_display));
	if (res)
		res->img = malloc(sizeof(t_image));
	if (!res || !res->img)
		exit_program(res, 1, NULL);
	res->size = max_size;
	res->min = min;
	res->max = max;
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
	set_hooks(res);
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

/*
	colors: brown 3, dark violet, darkest blue, blue 5, blue 4, blue 3, blue 2,
		blue 1, blue 0, lightest blue, lightest yellow, light yellow, dirty yellow,
		brown 0, brown 1, brown 2
*/
unsigned int	get_color(int n_iter)
{
	int	colors[16];

	colors[0] = 0x421E0F;
	colors[1] = 0x19071A;
	colors[2] = 0x09012F;
	colors[3] = 0x040449;
	colors[4] = 0x000764;
	colors[5] = 0x0C2C8A;
	colors[6] = 0x1852B1;
	colors[7] = 0x397DD1;
	colors[8] = 0x86B5E5;
	colors[9] = 0xD3ECF8;
	colors[10] = 0xF1E9BF;
	colors[11] = 0xF8C95F;
	colors[12] = 0xFFAA00;
	colors[13] = 0xCC8000;
	colors[14] = 0x995700;
	colors[15] = 0x6A3403;
	if (n_iter < MAX_ITERATIONS)
		return (colors[n_iter % 16]);
	return (0x000000);
}
