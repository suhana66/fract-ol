/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susajid <susajid@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:07:01 by susajid           #+#    #+#             */
/*   Updated: 2024/01/09 14:59:00 by susajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_display	*build_display(int width, int height, char *title)
{
	t_display	*result;

	result = malloc(sizeof(t_display));
	result->mlx = mlx_init();
	if (!result || !result->mlx)
		exit_program(result, 2, "can not establish connection to x-server\n");
	result->win = mlx_new_window(result->mlx, width, height, title);
	if (!result->win)
		exit_program(result, 3, "can not create window to display fractal\n");
	result->img = mlx_new_image(result->win, width, height);
	if (!result->img)
		exit_program(result, 4, "can not display fractal on window\n");
	mlx_hook(result->win, ON_DESTROY, 0, exit_hook, result);
	return (result);
}

void	exit_program(t_display *display, int exit_code, char *msg)
{
	if (exit_code == 1)
		msg = "a memory allocation error occured\n";
	if (msg)
		ft_printf(msg);
	if (!display)
		return ;
	if (display->img)
		mlx_destroy_image(display->mlx, display->img);
	if (display->win && display->mlx)
		mlx_destroy_window(display->mlx, display->win);
	if (display->mlx)
		free(display->mlx);
	free(display);
	exit(exit_code);
}

void	img_pixel_put(void	*image, int x, int y, int color)
{
}

double	pixel_to_complex(int pixel, double start, double end, int len)
{
	return (start + pixel / len * (end - start));
}

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
*/
int	check_divergence(t_complex z, t_complex c)
{
	int			n;
	double		temp;

	n = 0;
	while (z.r * z.r + z.i * z.i <= 4 && n < MAX_ITERATIONS)
	{
		temp = z.r * z.r - z.i * z.i + c.r;
		z.i = 2 * z.r * z.i + c.i;
		z.r = temp;
		n++;
	}
	return (n);
}
