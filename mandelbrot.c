/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susajid <susajid@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:00:12 by susajid           #+#    #+#             */
/*   Updated: 2024/01/05 16:34:44 by susajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
	(x, y) denotes the the pixel in the window
	(c_real, c_imaginary) denotes a complex number of the form
		c_real + c_imaginary(i), which can be plotted on the complex plane,
		where the x-axis denotes the real part of the complex number
		and the y-axis denotes the imaginary part of the complex number
*/
void	mandelbrot(void)
{
	int			x;
	int			y;
	double		a;
	double		b;
	t_display	*display;

	display = build_display(WIDTH, HEIGHT, "mandelbrot");
	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			a = pixel_to_complex(x, -2, 2, WIDTH);
			b = pixel_to_complex(y, -2, 2, HEIGHT);
		}
	}
	mlx_loop(display->mlx);
	(void)display;
}
