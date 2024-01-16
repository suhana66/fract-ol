/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susajid <susajid@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:09:07 by susajid           #+#    #+#             */
/*   Updated: 2024/01/16 15:44:00 by susajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdbool.h>
# include <math.h>
# include "libft.h"
# include "mlx.h"

# define MAX_WIDTH 1250
# define MAX_HEIGHT 1250
# define MAX_ITERATIONS 100

// general events
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

// key events
enum
{
	KEY_ESC = 53
};

// mouse events
enum
{
	LEFT_CLICK = 1,
	RIGHT_CLICK = 2,
	MIDDLE_CLICK = 3,
	SCROLL_UP = 4,
	SCROLL_DOWN = 5
};

typedef struct s_pixel
{
	int	x;
	int	y;
}	t_pixel;

typedef struct s_complex
{
	double	r;
	double	i;
}	t_complex;

typedef struct s_image
{
	void	*image;
	char	*buffer;
	int		bpp;
	int		line_length;
	int		endian;
}	t_image;

typedef struct s_display
{
	void		*mlx;
	void		*win;
	t_image		*img;
	t_pixel		size;
	t_complex	min;
	t_complex	max;
	void		*var;
	void		(*render)(struct s_display *);
}	t_display;

void			mandelbrot(t_display *display);
void			julia(t_display	*display);

t_display		*build_display(char *title, t_complex limits[2],
					void (*render)(struct s_display *), void *var);
void			set_hooks(t_display	*display);
void			exit_program(t_display *display, int exit_code, char *msg);
void			put_pixel(t_image *img, t_pixel pixel, int color);
unsigned int	get_color(int n_iter);

t_complex		pixel_to_complex(t_pixel pixel, t_complex min, t_complex max,
					t_pixel len);
int				get_divergence(t_complex z, t_complex c);
void			closest_size(int *width, int *height,
					double ratio_x, double ratio_y);

#endif /* FRACTOL_H */