/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susajid <susajid@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:00:12 by susajid           #+#    #+#             */
/*   Updated: 2024/01/10 13:30:30 by susajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
	(x, y) denotes the pixel in the window

	Requirement to prevent fractal distortion
	-----------------------------------------
	=>	ASPECT RATIO
	=>	width	max_x - min_x
		----- = -------------
		height	max_y - min_y
*/
void	mandelbrot(void)
{
	int			x;
	int			y;
	int			n_iter;
	double		max_x;
	double		min_x;
	double		max_y;
	double		min_y;
	t_display	*display;

	min_y = -1.25;
	max_y = 1.25;
	min_x = -2.25;
	max_x = 1;
	display = build_display(WIDTH, HEIGHT, "mandelbrot");
	build_image(display, WIDTH, HEIGHT, (max_x - min_x) / (max_y - min_y));
	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			n_iter = check_divergence((t_complex){0, 0},
					(t_complex){pixel_to_complex(x, min_x, max_x, WIDTH),
					pixel_to_complex(y, min_y, max_y, HEIGHT)});
			if (n_iter == MAX_ITERATIONS)
				put_pixel(display->img, x, y, 0x000000);
			else
				put_pixel(display->img, x, y, 0xFFFFFF);
		}
	}
	mlx_put_image_to_window(display->mlx, display->win,
		display->img->image, 0, 0);
	mlx_loop(display->mlx);
}
