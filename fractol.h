/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susajid <susajid@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 11:47:14 by susajid           #+#    #+#             */
/*   Updated: 2024/01/11 13:50:46 by susajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdbool.h>
# include <math.h>
# include "libft.h"
# include "mlx.h"

# define WIDTH 800
# define HEIGHT 600
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

typedef struct s_display
{
	void			*mlx;
	void			*win;
	struct s_image	*img;
}	t_display;

typedef struct s_image
{
	void	*image;
	char	*buffer;
	int		bpp;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}			t_image;

typedef struct s_complex
{
	double	r;
	double	i;
}	t_complex;

void		mandelbrot(t_complex min, t_complex max);
void		julia(t_complex constant);

t_display	*build_display(char *title, double x_axis_len, double y_axis_len);
void		build_image(t_display *display, int width, int height);
void		exit_program(t_display *display, int exit_code, char *msg);
void		put_pixel(t_image *img, int x, int y, int color);

double		pixel_to_complex(int pixel, double start, double end, int len);
int			check_divergence(t_complex z, t_complex c);
void		closest_size(int *width, int *height,
				double ratio_x, double ratio_y);

int			mouse_hook(int move, t_display *display);
int			key_hook(int key, t_display *display);
int			exit_hook(t_display *display);

#endif /* FRACTOL_H */