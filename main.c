/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susajid <susajid@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 11:29:01 by susajid           #+#    #+#             */
/*   Updated: 2024/01/08 14:47:40 by susajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static bool	parse_string(char *str, char *model);
static int	parse_range(char *str, double *result, double r_min, double r_max);

int	main(int argc, char **argv)
{
	t_complex	*c;

	if (argc == 2 && parse_string(argv[1], "mandelbrot"))
		return (mandelbrot(), 0);
	if (argc == 4 && parse_string(argv[1], "julia"))
	{
		c = malloc(sizeof(t_complex));
		if (!c || parse_range(argv[2], &(c->a), -2, 2)
			|| parse_range(argv[3], &(c->b), -2, 2))
			return (ft_printf("an invalid constant was given for julia fractal,"
					" a and b in a + bi must be in the range [-2, 2]\n"),
				free(c), 1);
		return (julia(c), free(c), 0);
	}
	return (ft_printf("usage: ./fractol <fractal> [a] [b]\n"
			" fractals: mandelbrot, julia\n"
			" constant: [a] [b]\n"
			"   the julia fractal requires a constant complex number in the"
			" form a + bi, where a and b are floating numbers\n"), 2);
}

static bool	parse_string(char *str, char *model)
{
	if (!str && !model)
		return (true);
	if (!str || !model)
		return (false);
	while (ft_isspace(*str))
		str++;
	while (*str && *model && ft_tolower(*str) == ft_tolower(*model))
	{
		model++;
		str++;
	}
	while (ft_isspace(*str))
		str++;
	if (*str || *model)
		return (false);
	return (true);
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
