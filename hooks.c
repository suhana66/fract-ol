/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susajid <susajid@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:54:04 by susajid           #+#    #+#             */
/*   Updated: 2024/01/11 12:50:33 by susajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_hook(int move, t_display *display)
{
	(void)move;
	(void)display;
	return (0);
}

int	key_hook(int key, t_display *display)
{
	if (key == KEY_ESC)
		return (exit_hook(display));
	return (0);
}

int	exit_hook(t_display *display)
{
	return (exit_program(display, 0, "exited\n"), 0);
}
