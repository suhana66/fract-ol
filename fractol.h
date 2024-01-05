/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susajid <susajid@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 11:47:14 by susajid           #+#    #+#             */
/*   Updated: 2024/01/05 13:43:42 by susajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdbool.h>
# include "libft.h"
# include "mlx.h"

# define WIDTH 1920
# define HEIGHT 1080

enum e_fractal
{
	MANDELBROT,
	JULIA
};

// events
enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

// keys
# define KEY_ESC 65307

typedef struct s_display
{
	void	*mlx;
	void	*win;
	void	*img;
}	t_display;

t_display	*build_display(int width, int height, char *title);
void		close_display(t_display *display);

#endif /* FRACTOL_H */