/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susajid <susajid@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 11:29:01 by susajid           #+#    #+#             */
/*   Updated: 2024/01/04 12:12:26 by susajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	parse_range(char *str, double *result, double r_min, double r_max);

int	main(int argc, char **argv)
{
	double	a;
	double	b;

	if (!((argc == 2 && ft_strncmp(argv[1], "mandelbrot", 11) == 0)
			|| (argc == 4 && ft_strncmp(argv[1], "julia", 6) == 0)))
	{
		ft_printf("usage: ./fractol <fractal> [a] [b]\n"
			" fractals: mandelbrot, julia\n"
			" constant: [a] [b]\n"
			"   a constant complex number of the form a + bi, where a and b are"
			" floating numbers is required only if the fractal is \"julia\"\n");
		return (1);
	}
	if (ft_strncmp(argv[1], "mandelbrot", 11) == 0)
		build_mandelbrot();
	else
	{
		if (parse_range(argv[2], &a, -2, 2) || parse_range(argv[3], &b, -2, 2))
			return (ft_printf("an invalid constant was given for julia fractal"
					", a and b in a + bi must be in the range [-2, 2]\n"), 2);
		build_julia(a, b);
	}
	return (0);
}

static int	parse_range(char *str, double *result, double r_min, double r_max)
{
	double	sign;

	while (str && ft_isspace(*str))
		str++;
	sign = 1;
	if (str && (*str == '-' || *str == '+') && str++ && (*(str - 1) == '-'))
		sign = -1;
	if (!str || !result || !ft_isdigit(*str))
		return (1);
	*result = 0;
	while (ft_isdigit(*str) && *result >= r_min && *result <= r_max)
		*result = *result * 10.0 + (*str++ - '0') * sign;
	if (*str == '.')
		str++;
	while (ft_isdigit(*str) && *result >= r_min && *result <= r_max)
	{
		*result += (*str++ - '0') * 0.1 * sign;
		sign *= 0.1;
	}
	while (ft_isspace(*str))
		str++;
	if (*str || *result < r_min || *result > r_max)
		return (2);
	return (0);
}
