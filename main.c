/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susajid <susajid@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 11:29:01 by susajid           #+#    #+#             */
/*   Updated: 2024/01/12 13:12:12 by susajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static bool	parse_string(char *str, char *model);
static int	parse_range(char *str, double *result, double r_min, double r_max);

int	main(int argc, char **argv)
{
	int			width;
	int			height;
	t_complex	c;

	width = 800;
	height = 600;
	if (argc == 2 && parse_string(argv[1], "mandelbrot"))
		return (mandelbrot(width, height,
				(t_complex){-2, -1.5}, (t_complex){1, 1.5}), 0);
	if (argc == 4 && parse_string(argv[1], "julia"))
	{
		if (parse_range(argv[2], &c.r, -2, 2)
			|| parse_range(argv[3], &c.i, -2, 2))
			exit_program(NULL, 2, "an invalid constant was given for julia "
				"fractal, a and b in a + bi must be in the range [-2, 2]\n");
		return (julia(c), 0);
	}
	exit_program(NULL, 3, "usage: ./fractol <fractal> [a] [b]\n"
		" fractals: mandelbrot, julia\n"
		" constant: [a] [b]\n"
		"   the julia fractal requires a constant complex number in the"
		" form a + bi, where a and b are floating numbers\n");
}

static bool	parse_string(char *str, char *model)
{
	if (!str && !model)
		return (true);
	if (!str || !model)
		return (false);
	while (ft_isspace(*str))
		str++;
	while (*str && *model
		&& ft_tolower((unsigned char)*str) == ft_tolower((unsigned char)*model))
	{
		model++;
		str++;
	}
	while (ft_isspace(*str))
		str++;
	return (!*str && !*model);
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
