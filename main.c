/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susajid <susajid@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 11:29:01 by susajid           #+#    #+#             */
/*   Updated: 2024/01/05 13:44:14 by susajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	get_user_input(int argc, char **argv, double *a, double *b);
static bool	parse_string(char *str, char *model);
static char	*parse_range(char *str, double *result, double r_min, double r_max);

int	main(int argc, char **argv)
{
	int			fractal;
	double		a;
	double		b;
	t_display	*display;

	fractal = get_user_input(argc, argv, &a, &b);
	if (fractal == MANDELBROT)
		display = build_display(WIDTH, HEIGHT, "mandelbrot");
	else if (fractal == JULIA)
		display = build_display(WIDTH, HEIGHT, "julia");
	else
		return (1);
	if (!display)
		return (2);
	return (0);
}

static int	get_user_input(int argc, char **argv, double *a, double *b)
{
	enum e_fractal	result;

	if (argc == 2 && parse_string(argv[1], "mandelbrot"))
		result = MANDELBROT;
	else if (argc == 4 && parse_string(argv[1], "julia"))
		result = JULIA;
	else
		return (ft_printf("usage: ./fractol <fractal> [a] [b]\n"
				" fractals: mandelbrot, julia\n"
				" constant: [a] [b]\n"
				"   the julia fractal requires a constant complex number in the"
				" form a + bi, where a and b are floating numbers\n"), -1);
	if (result == JULIA
		&& (!parse_range(argv[2], a, -2, 2) || !parse_range(argv[3], b, -2, 2)))
		return (ft_printf("an invalid constant was given for julia fractal"
				", a and b in a + bi must be in the range [-2, 2]\n"), -2);
	return (result);
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

static char	*parse_range(char *str, double *result, double r_min, double r_max)
{
	double	sign;

	while (str && ft_isspace(*str))
		str++;
	sign = 1;
	if (str && (*str == '-' || *str == '+') && str++ && (*(str - 1) == '-'))
		sign = -1;
	if (!str || !result || !ft_isdigit(*str))
		return (NULL);
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
	if ((*str && !ft_isspace(*str)) || *result < r_min || *result > r_max)
		return (NULL);
	while (ft_isspace(*str))
		str++;
	return (str);
}
