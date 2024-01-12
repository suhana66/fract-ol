/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susajid <susajid@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:18:53 by susajid           #+#    #+#             */
/*   Updated: 2024/01/12 13:06:10 by susajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

/*
	Complex number formulas
	-----------------------
	1)	Multiplication of complex numbers
		(a + bi)(c + di) = (ac - bd) + i(ad + bc)
	2)	(a + bi)^2
		=> (a + bi)(a + bi)
		=> (a^2 - b^2) + i(ab + ab)
		=> a^2 - b^2 + 2ab(i)
	3)	Absolute value of complex number
		=> c = a + bi, |c|^2 = a^2 + b^2
		=> |c| = √(a^2 + b^2)
*/
int	get_divergence(t_complex z, t_complex c)
{
	int			n;
	double		temp;

	n = 0;
	while (sqrt(z.r * z.r + z.i * z.i) <= 2 && n < MAX_ITERATIONS)
	{
		temp = z.r * z.r - z.i * z.i + c.r;
		z.i = 2 * z.r * z.i + c.i;
		z.r = temp;
		n++;
	}
	return (n);
}

double	pixel_to_complex(int pixel, double start, double end, int len)
{
	return (start + (end - start) / len * pixel);
}

void	closest_size(int *width, int *height, double ratio_x, double ratio_y)
{
	double	temp;
	double	dividend;
	double	divisor;
	int		k;

	if (!width || !height)
		return ;
	dividend = fmax(ratio_x, ratio_y);
	divisor = fmin(ratio_x, ratio_y);
	while (divisor != 0)
	{
		temp = divisor;
		divisor = fmod(dividend, divisor);
		dividend = temp;
	}
	ratio_x /= dividend;
	ratio_y /= dividend;
	k = (int)fmin(*width / ratio_x, *height / ratio_y);
	*width = k * ratio_x;
	*height = k * ratio_y;
}
