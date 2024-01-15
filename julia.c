/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susajid <susajid@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:00:12 by susajid           #+#    #+#             */
/*   Updated: 2024/01/15 14:50:59 by susajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Z0 varies, C remains constant, in Zn+1 = (Zn)^2 + C
void	julia(t_pixel max_size, t_complex min, t_complex max, t_complex c)
{
	t_pixel		pixel;
	t_display	*display;

	display = build_display(max_size, "julia",
			(t_complex){max.r - min.r, max.i - min.i});
	pixel.x = -1;
	while (++pixel.x < display->size.x)
	{
		pixel.y = -1;
		while (++pixel.y < display->size.y)
		{
			put_pixel(display->img, pixel, get_color(
					get_divergence(
						pixel_to_complex(pixel, min, max, display->size), c)));
		}
	}
	mlx_put_image_to_window(display->mlx, display->win,
		display->img->image, 0, 0);
	mlx_loop(display->mlx);
}
