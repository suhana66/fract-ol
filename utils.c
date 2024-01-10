/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susajid <susajid@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:07:01 by susajid           #+#    #+#             */
/*   Updated: 2024/01/11 12:06:41 by susajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_display	*build_display(int width, int height, char *title)
{
	t_display	*result;

	result = malloc(sizeof(t_display));
	if (!result)
		exit_program(result, 1, NULL);
	result->mlx = mlx_init();
	if (!result || !result->mlx)
		exit_program(result, 2, "could not establish connection to x-server\n");
	result->win = mlx_new_window(result->mlx, width, height, title);
	if (!result->win)
		exit_program(result, 3, "could not create window to display fractal\n");
	mlx_hook(result->win, ON_DESTROY, 0, exit_hook, result);
	return (result);
}

void	build_image(t_display *display, int width, int height)
{
	t_image	*img;

	if (!display)
		return ;
	img = malloc(sizeof(t_image));
	if (!img)
		exit_program(display, 1, NULL);
	img->image = mlx_new_image(display->win, width, height);
	if (!img->image)
		exit_program(display, 4, "could not display fractal on window\n");
	img->buffer = mlx_get_data_addr(img->image, &img->bpp, &img->line_length,
			&img->endian);
	display->img = img;
}

void	exit_program(t_display *display, int exit_code, char *msg)
{
	if (exit_code == 1 && msg == NULL)
		msg = "a memory allocation error occured\n";
	if (msg)
		ft_printf(msg);
	if (!display)
		exit(exit_code);
	if (display->img && display->img->image && display->mlx)
		mlx_destroy_image(display->mlx, display->img->image);
	free(display->img);
	if (display->win && display->mlx)
		mlx_destroy_window(display->mlx, display->win);
	if (display->mlx)
		free(display->mlx);
	free(display);
	exit(exit_code);
}

void	put_pixel(t_image *img, int x, int y, int color)
{
	char	*pixel;

	if (!img)
		return ;
	pixel = img->buffer + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int *)pixel = color;
}

double	pixel_to_complex(int pixel, double start, double end, int len)
{
	return (start + (end - start) / len * pixel);
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

void	closest_size(int *width, int *height, double ratio_x, double ratio_y)
{
	(void)width;
	(void)height;
	(void)ratio_x;
	(void)ratio_y;
}
