/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susajid <susajid@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:00:12 by susajid           #+#    #+#             */
/*   Updated: 2024/01/12 08:14:54 by susajid          ###   ########.fr       */
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
void	mandelbrot(int width, int height, t_complex min, t_complex max)
{
	int			x;
	int			y;
	int			n_iter;
	t_display	*vis;

	vis = build_display(width, height, "mandelbrot",
			(t_complex){max.r - min.r, max.i - min.i});
	x = -1;
	while (++x < vis->img->width)
	{
		y = -1;
		while (++y < vis->img->height)
		{
			n_iter = check_divergence((t_complex){0, 0}, (t_complex){
					pixel_to_complex(x, min.r, max.r, vis->img->width),
					pixel_to_complex(y, min.i, max.i, vis->img->height)});
			if (n_iter == MAX_ITERATIONS)
				put_pixel(vis->img, x, y, 0x000000);
			else
				put_pixel(vis->img, x, y, 0xFFFFFF);
		}
	}
	mlx_put_image_to_window(vis->mlx, vis->win, vis->img->image, (vis->width
			- vis->img->width) / 2, (vis->height - vis->img->height) / 2);
	mlx_loop(vis->mlx);
}
