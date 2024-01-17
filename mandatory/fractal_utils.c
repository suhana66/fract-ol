/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susajid <susajid@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:07:01 by susajid           #+#    #+#             */
/*   Updated: 2024/01/16 16:04:23 by susajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_image	*build_image(void *win, int width, int height);

/*
	Requirement to prevent fractal distortion
	-----------------------------------------
	=>	ASPECT RATIO
	=>	width	max_x - min_x
		----- = -------------
		height	max_y - min_y
*/
t_display	*build_display(char *title, t_complex limits[2],
				void (*render)(struct s_display *), void *var)
{
	t_display	*res;

	res = malloc(sizeof(t_display));
	if (!res)
		exit_program(res, 1, NULL);
	res->size = (t_pixel){MAX_WIDTH, MAX_HEIGHT};
	closest_size(&res->size.x, &res->size.y,
		limits[1].r - limits[0].r, limits[1].i - limits[0].i);
	res->min = limits[0];
	res->max = limits[1];
	res->render = render;
	res->var = var;
	res->mlx = mlx_init();
	if (!res->mlx)
		exit_program(res, 2, "could not establish connection to x-server\n");
	res->win = mlx_new_window(res->mlx, res->size.x, res->size.y, title);
	if (!res->win)
		exit_program(res, 3, "could not create window to display fractal\n");
	res->img = build_image(res->win, res->size.x, res->size.y);
	if (!res->img)
		exit_program(res, 4, "could not display fractal on window\n");
	set_hooks(res);
	res->render(res);
	return (res);
}

static t_image	*build_image(void *win, int width, int height)
{
	t_image	*result;

	result = malloc(sizeof(t_image));
	if (!result)
		return (NULL);
	result->image = mlx_new_image(win, width, height);
	if (!result->image)
		return (free(result), NULL);
	result->buffer = mlx_get_data_addr(result->image, &result->bpp,
			&result->line_length, &result->endian);
	return (result);
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
