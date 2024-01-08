/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susajid <susajid@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:00:12 by susajid           #+#    #+#             */
/*   Updated: 2024/01/08 15:10:54 by susajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	calculate_mandelbrot(t_complex c);

// (x, y) denotes the pixel in the window
void	mandelbrot(void)
{
	int			x;
	int			y;
	t_complex	c;
	t_display	*display;

	display = build_display(WIDTH, HEIGHT, "mandelbrot");
	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			c = (t_complex){pixel_to_complex(x, -2, 2, WIDTH),
				pixel_to_complex(y, -2, 2, HEIGHT)};
			calculate_mandelbrot(c);
		}
	}
	mlx_loop(display->mlx);
}

/*
	Complex number formulas
	-----------------------
	1)	Multiplication of complex numbers
		(a + bi)(c + di) = (ac - bd) + i(ad + bc)
	2)	(a + bi)^2
		=> (a + bi)(a + bi)
		=> (a^2 + b^2) + i(ab + ab)
		=> a^2 + b^2 + 2ab(i)
	3)	Absolute value of complex number
		=> c = a + bi, |c|^2 = a^2 + b^2
*/
static void	calculate_mandelbrot(t_complex c)
{
	int	i;

	i = 0;
	while (c.a * c.a - c.b * c.b < 4 && i < MAX_ITERATIONS)
	{
	}
	if (i == MAX_ITERATIONS)
	{
	}
	else
	{
	}
}
