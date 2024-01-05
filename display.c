/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susajid <susajid@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:07:01 by susajid           #+#    #+#             */
/*   Updated: 2024/01/05 12:44:12 by susajid          ###   ########.fr       */
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
		return (ft_printf("can not establish connection to x-server\n"),
			close_display(result), NULL);
	result->win = mlx_new_window(result->mlx, width, height, title);
	if (!result->win)
		return (ft_printf("can not create window to display fractal\n"),
			close_display(result), NULL);
	result->img = mlx_new_image(result->win, width, height);
	if (!result->img)
		return (ft_printf("can not display fractal on window\n"),
			close_display(result), NULL);
	mlx_loop(result->mlx);
	return (result);
}

void	close_display(t_display *display)
{
	if (display->img)
		mlx_destroy_image(display->mlx, display->img);
	if (display->win && display->mlx)
		mlx_destroy_window(display->mlx, display->win);
	if (display->mlx)
		free(display->mlx);
	free(display);
}
