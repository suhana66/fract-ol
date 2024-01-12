/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susajid <susajid@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:00:12 by susajid           #+#    #+#             */
/*   Updated: 2024/01/12 10:37:47 by susajid          ###   ########.fr       */
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
void	mandelbrot(int max_width, int max_height, t_complex min, t_complex max)
{
	int			x;
	int			y;
	t_display	*display;

	display = build_display(max_width, max_height, "mandelbrot",
			(t_complex){max.r - min.r, max.i - min.i});
	x = -1;
	while (++x < display->width)
	{
		y = -1;
		while (++y < display->height)
		{
			put_pixel(display->img, x, y, get_color(
					get_divergence((t_complex){0, 0}, (t_complex){
						pixel_to_complex(x, min.r, max.r, display->width),
						pixel_to_complex(y, min.i, max.i, display->height)
					})));
		}
	}
	mlx_put_image_to_window(display->mlx, display->win,
		display->img->image, 0, 0);
	mlx_loop(display->mlx);
}
