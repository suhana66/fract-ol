/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susajid <susajid@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 11:47:14 by susajid           #+#    #+#             */
/*   Updated: 2024/01/03 10:05:06 by susajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "stdbool.h"
# include "libft/libft.h"

void	build_mandelbrot(void);
void	build_julia(double x, double y);

#endif /* FRACTOL_H */