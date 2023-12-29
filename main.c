/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susajid <susajid@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 11:29:01 by susajid           #+#    #+#             */
/*   Updated: 2024/01/02 16:12:43 by susajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	if (!((argc == 2 && ft_strncmp(argv[1], "mandelbrot", 11) == 0)
			|| (argc == 4 && ft_strncmp(argv[1], "julia", 6) == 0)))
	{
		ft_printf("usage: ./fractol [fractal] <constant>\n"
			" fractals:\n"
			"   --> mandelbrot\n"
			"   --> julia\n"
			" constant:\n"
			"   a constant complex number of the form a + bi, where a and b are"
			" floating numbers is required only if the fractal is \"julia\"\n");
		return (1);
	}
	return (0);
}
