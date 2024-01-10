/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susajid <susajid@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:00:12 by susajid           #+#    #+#             */
/*   Updated: 2024/01/11 12:04:19 by susajid          ###   ########.fr       */
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
void	mandelbrot(t_complex min, t_complex max)
{
	int			x;
	int			y;
	int			n_iter;
	int			img_width;
	int			img_height;
	t_display	*display;

	display = build_display(WIDTH, HEIGHT, "mandelbrot");
	img_width = WIDTH;
	img_height = HEIGHT;
	closest_size(&img_width, &img_height, max.r - min.r, max.i - min.i);
	build_image(display, img_width, img_height);
	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			n_iter = check_divergence((t_complex){0, 0},
					(t_complex){pixel_to_complex(x, min.r, max.r, WIDTH),
					pixel_to_complex(y, min.i, max.i, HEIGHT)});
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
