/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susajid <susajid@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:00:12 by susajid           #+#    #+#             */
/*   Updated: 2024/01/15 13:16:39 by susajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Z0 remains constant (Z0 = 0), C varies, in Zn+1 = (Zn)^2 + C
void	mandelbrot(t_pixel max_size, t_complex min, t_complex max)
{
	t_pixel		pixel;
	t_display	*display;

	display = build_display(max_size, "mandelbrot",
			(t_complex){max.r - min.r, max.i - min.i});
	pixel.x = -1;
	while (++pixel.x < display->size.x)
	{
		pixel.y = -1;
		while (++pixel.y < display->size.y)
		{
			put_pixel(display->img, pixel, get_color(
					get_divergence((t_complex){0, 0},
						pixel_to_complex(pixel, min, max, display->size))));
		}
	}
	mlx_put_image_to_window(display->mlx, display->win,
		display->img->image, 0, 0);
	mlx_loop(display->mlx);
}
