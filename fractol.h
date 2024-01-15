/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susajid <susajid@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 11:47:14 by susajid           #+#    #+#             */
/*   Updated: 2024/01/15 15:02:08 by susajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdbool.h>
# include <math.h>
# include "libft.h"
# include "mlx.h"

# define MAX_ITERATIONS 100

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
enum
{
	KEY_ESC = 65307
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

typedef struct s_display
{
	void			*mlx;
	void			*win;
	struct s_image	*img;
	struct s_pixel	size;
}	t_display;

typedef struct s_image
{
	void	*image;
	char	*buffer;
	int		bpp;
	int		line_length;
	int		endian;
}			t_image;

void			mandelbrot(t_pixel max_size, t_complex min, t_complex max);
void			julia(t_pixel max_size, t_complex min, t_complex max,
					t_complex constant);

t_display		*build_display(t_pixel max_size, char *title, t_complex limit);
void			exit_program(t_display *display, int exit_code, char *msg);
void			put_pixel(t_image *img, t_pixel pixel, int color);
unsigned int	get_color(int n_iter);

t_complex		pixel_to_complex(t_pixel pixel, t_complex min, t_complex max,
					t_pixel len);
int				get_divergence(t_complex z, t_complex c);
void			closest_size(int *width, int *height,
					double ratio_x, double ratio_y);

int				mouse_hook(int move, t_display *display);
int				key_hook(int key, t_display *display);
int				exit_hook(t_display *display);

#endif /* FRACTOL_H */