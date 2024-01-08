/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susajid <susajid@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 11:47:14 by susajid           #+#    #+#             */
/*   Updated: 2024/01/08 14:31:33 by susajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdbool.h>
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
	void	*mlx;
	void	*win;
	void	*img;
}	t_display;

typedef struct s_complex
{
	double	a;
	double	b;
}	t_complex;

t_display	*build_display(int width, int height, char *title);
void		close_display(t_display *display, int exit_code, char *msg);

int			key_hook(int key, t_display *display);
int			exit_hook(t_display *display);

void		mandelbrot(void);
void		julia(t_complex *constant);

double		pixel_to_complex(int pixel, double start, double end, int len);

#endif /* FRACTOL_H */