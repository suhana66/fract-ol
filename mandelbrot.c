/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susajid <susajid@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:00:12 by susajid           #+#    #+#             */
/*   Updated: 2024/01/08 17:12:02 by susajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// (x, y) denotes the pixel in the window
void	mandelbrot(void)
{
	int			x;
	int			y;
	int			n_iter;
	t_display	*display;

	display = build_display(WIDTH, HEIGHT, "mandelbrot");
	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			n_iter = check_divergence((t_complex){0, 0},
					(t_complex){pixel_to_complex(x, -2, 2, WIDTH),
					pixel_to_complex(y, -2, 2, HEIGHT)});
			if (n_iter == MAX_ITERATIONS)
			{
			}
			else
			{
			}
		}
	}
	mlx_loop(display->mlx);
}
