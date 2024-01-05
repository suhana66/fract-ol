/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susajid <susajid@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:00:12 by susajid           #+#    #+#             */
/*   Updated: 2024/01/05 17:11:14 by susajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	calculate_mandelbrot(double x, double y);

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
			calculate_mandelbrot(a, b);
		}
	}
	mlx_loop(display->mlx);
	(void)display;
}

/*
	Complex number formulas
	-----------------------
	1)	Multiplication of complex numbers
		(a + bi)(c + di) = (ac - bd) + i(ad + bc)
	2)	complex number => a + bi
		complex conjugate => a - bi
	3)	complex number * complex conjugate
		=> real number
		=> (a + bi)(a - bi)
		=> (a^2 - b^2) + i(-ab + ba)
		=> a^2 - b^2
	4) (a + bi)^2
		=> (a + bi)(a + bi)
		=> (a^2 + b^2) + i(ab + ab)
		=> a^2 + b^2 + 2ab(i)
*/
static void	calculate_mandelbrot(double x, double y)
{
	int	i;

	i = 0;
	while (x * x - y * y < 4 && i < MAX_ITERATIONS)
	{
	}
	if (i == MAX_ITERATIONS)
	{
	}
	else
	{
	}
}
