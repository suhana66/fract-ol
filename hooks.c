/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susajid <susajid@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:54:04 by susajid           #+#    #+#             */
/*   Updated: 2024/01/16 13:22:00 by susajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	mouse_hook(int move, int x, int y, t_display *display);
static int	key_hook(int key, t_display *display);
static int	exit_hook(t_display *display);
static void	zoom(t_display *display, double zoom);

void	set_hooks(t_display	*display)
{
	if (!display)
		return ;
	mlx_hook(display->win, ON_DESTROY, 0, exit_hook, display);
	mlx_hook(display->win, ON_MOUSEDOWN, 0, mouse_hook, display);
	mlx_hook(display->win, ON_KEYDOWN, 0, key_hook, display);
}

static int	mouse_hook(int move, int x, int y, t_display *display)
{
	(void)x;
	(void)y;
	if (move == SCROLL_UP)
		zoom(display, 0.5);
	if (move == SCROLL_DOWN)
		zoom(display, -0.5);
	return (0);
}

static int	key_hook(int key, t_display *display)
{
	if (key == KEY_ESC)
		exit_hook(display);
	return (0);
}

static int	exit_hook(t_display *display)
{
	return (exit_program(display, 0, "exited\n"), 0);
}

static void	zoom(t_display *display, double zoom)
{
	t_complex center;
	t_complex len;

	if (!display)
		return ;
	center.r = (display->max.r + display->min.r) / 2;
	center.i = (display->max.i + display->min.i) / 2;
	len.r = display->max.r - display->min.r;
	len.i = display->max.i - display->min.i;
	len.r *= (1 + zoom);
	len.i *= (1 + zoom);
	display->min.r = center.r - len.r / 2;
	display->max.r = center.r + len.r / 2;
	display->min.i = center.i - len.i / 2;
	display->max.i = center.i + len.i / 2;
}
