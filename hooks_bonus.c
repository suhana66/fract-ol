/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susajid <susajid@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:54:04 by susajid           #+#    #+#             */
/*   Updated: 2024/01/17 12:24:09 by susajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static int	mouse_hook(int move, int x, int y, t_display *display);
static int	key_hook(int key, t_display *display);
static int	exit_hook(t_display *display);
static void	move(t_display *display, double zoom,
				double shift_r, double shift_i);

void	set_hooks(t_display *display)
{
	if (!display)
		return ;
	mlx_hook(display->win, ON_DESTROY, 0, exit_hook, display);
	mlx_hook(display->win, ON_MOUSEDOWN, 0, mouse_hook, display);
	mlx_hook(display->win, ON_KEYDOWN, 0, key_hook, display);
}

static int	mouse_hook(int code, int x, int y, t_display *display)
{
	(void)x;
	(void)y;
	if (code == SCROLL_UP)
		move(display, 0.25, 0, 0);
	if (code == SCROLL_DOWN)
		move(display, -0.25, 0, 0);
	return (0);
}

static int	key_hook(int key, t_display *display)
{
	if (key == KEY_ESC)
		exit_hook(display);
	if (key == KEY_ARROW_UP)
		move(display, 0, 0, 0.0625);
	if (key == KEY_ARROW_DOWN)
		move(display, 0, 0, -0.0625);
	if (key == KEY_ARROW_RIGHT)
		move(display, 0, 0.0625, 0);
	if (key == KEY_ARROW_LEFT)
		move(display, 0, -0.0625, 0);
	return (0);
}

static int	exit_hook(t_display *display)
{
	exit_program(display, 0, "exited\n");
	return (0);
}

static void	move(t_display *display, double zoom,
				double shift_r, double shift_i)
{
	t_complex	center;
	t_complex	len;

	if (!display)
		return ;
	center.r = (display->max.r + display->min.r) / 2.0;
	center.i = (display->max.i + display->min.i) / 2.0;
	len.r = display->max.r - display->min.r;
	len.i = display->max.i - display->min.i;
	len.r *= (1.0 + zoom);
	len.i *= (1.0 + zoom);
	display->min.r = center.r - len.r / 2.0;
	display->max.r = center.r + len.r / 2.0;
	display->min.i = center.i - len.i / 2.0;
	display->max.i = center.i + len.i / 2.0;
	display->max.r += len.r * shift_r;
	display->min.r += len.r * shift_r;
	display->max.i -= len.r * shift_i;
	display->min.i -= len.r * shift_i;
	display->render(display);
}
