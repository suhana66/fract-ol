/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susajid <susajid@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 11:29:01 by susajid           #+#    #+#             */
/*   Updated: 2023/12/29 12:48:38 by susajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	if (--argc != 1 || (ft_strncmp(argv[1], "Mandelbrot", 11)
			&& ft_strncmp(argv[1], "Julia", 6)))
	{
		ft_printf("usage: ./fractol [fractal]\n"
			" fractals:\n"
			"   --> Mandelbrot\n"
			"   --> Julia\n");
		return (1);
	}
	return (0);
}
