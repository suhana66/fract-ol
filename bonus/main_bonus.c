/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susajid <susajid@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 11:29:01 by susajid           #+#    #+#             */
/*   Updated: 2024/01/18 10:18:24 by susajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static bool	parse_string(char *str, char *model);
static int	parse_range(char *str, double *result, double r_min, double r_max);

int	main(int argc, char **argv)
{
	t_complex	c;
	t_complex	limits[2];
	t_display	*display;

	display = NULL;
	if (argc == 2 && parse_string(argv[1], "mandelbrot"))
	{
		limits[0] = (t_complex){-2.0, -1.5};
		limits[1] = (t_complex){1.0, 1.5};
		display = build_display("mandelbrot", limits, mandelbrot, NULL);
	}
	else if (argc == 4 && parse_string(argv[1], "julia"))
	{
		limits[0] = (t_complex){-2.0, -2.0};
		limits[1] = (t_complex){2.0, 2.0};
		if (parse_range(argv[2], &c.r, limits[0].r, limits[1].r)
			|| parse_range(argv[3], &c.i, limits[0].i, limits[1].i))
			exit_program(NULL, 2, "invalid constant; a + bi in range [-2,2]\n");
		display = build_display("julia", limits, julia, &c);
	}
	if (!display)
		exit_program(NULL, 3, "usage: ./fractol <fractal> [a] [b]\n fractals: "
			"julia, mandelbrot\n > for julia, input complex number (a + bi)\n");
	mlx_loop(display->mlx);
	return (0);
}

// Z0 remains constant (Z0 = 0), C varies, in Zn+1 = (Zn)^2 + C
void	mandelbrot(t_display *display)
{
	t_pixel		pixel;

	if (!display)
		return ;
	pixel.x = -1;
	while (++pixel.x < display->size.x)
	{
		pixel.y = -1;
		while (++pixel.y < display->size.y)
		{
			put_pixel(display->img, pixel, get_color(
					get_divergence((t_complex){0, 0},
						pixel_to_complex(pixel, display->min, display->max,
							display->size))));
		}
	}
	mlx_put_image_to_window(display->mlx, display->win,
		display->img->image, 0, 0);
}

// Z0 varies, C remains constant, in Zn+1 = (Zn)^2 + C
void	julia(t_display	*display)
{
	t_pixel		pixel;

	if (!display || !display->var)
		return ;
	pixel.x = -1;
	while (++pixel.x < display->size.x)
	{
		pixel.y = -1;
		while (++pixel.y < display->size.y)
		{
			put_pixel(display->img, pixel, get_color(
					get_divergence(
						pixel_to_complex(pixel, display->min, display->max,
							display->size), *(t_complex *)display->var)));
		}
	}
	mlx_put_image_to_window(display->mlx, display->win,
		display->img->image, 0, 0);
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
	if (!str || !result)
		return (1);
	*result = 0;
	while (ft_isdigit(*str) && *result >= r_min && *result <= r_max)
		*result = *result * 10.0 + (*str++ - '0') * sign;
	if (*str == '.' && str++ && *result == 0 && !ft_isdigit(*str))
		return (2);
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
