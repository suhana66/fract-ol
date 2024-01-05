/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susajid <susajid@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:07:01 by susajid           #+#    #+#             */
/*   Updated: 2024/01/05 16:14:25 by susajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_display	*build_display(int width, int height, char *title)
{
	t_display	*result;

	result = malloc(sizeof(t_display));
	if (result)
		result->mlx = mlx_init();
	if (!result || !result->mlx)
		close_display(result, 1, "can not establish connection to x-server\n");
	result->win = mlx_new_window(result->mlx, width, height, title);
	if (!result->win)
		close_display(result, 2, "can not create window to display fractal\n");
	result->img = mlx_new_image(result->win, width, height);
	if (!result->img)
		close_display(result, 3, "can not display fractal on window\n");
	mlx_hook(result->win, ON_DESTROY, 0, exit_hook, result);
	return (result);
}

void	close_display(t_display *display, int exit_code, char *msg)
{
	if (msg)
		ft_printf(msg);
	if (display->img)
		mlx_destroy_image(display->mlx, display->img);
	if (display->win && display->mlx)
		mlx_destroy_window(display->mlx, display->win);
	if (display->mlx)
		free(display->mlx);
	free(display);
	exit(exit_code);
}

double	pixel_to_complex(int pixel, double start, double end, int full_length)
{
	return (start + pixel / full_length * (end - start));
}
