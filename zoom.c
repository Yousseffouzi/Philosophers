/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yofouzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 03:51:43 by yofouzi           #+#    #+#             */
/*   Updated: 2025/04/14 03:51:45 by yofouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	update_bounds(t_fractal *fractol)
{
	fractol->min_real = -2.0 / fractol->zoom + fractol->offset_x;
	fractol->max_real = 2.0 / fractol->zoom + fractol->offset_x;
	fractol->min_imag = -2.0 / fractol->zoom + fractol->offset_y;
	fractol->max_imag = 2.0 / fractol->zoom + fractol->offset_y;
}

void	update_f(t_fractal *fractol)
{
	update_bounds(fractol);
	if (fractol->name == 1)
		mandelbrot(fractol);
	else if (fractol->name == 2)
		julia(fractol, fractol->c_real, fractol->c_img);
	mlx_put_image_to_window(fractol->mlx_connection, fractol->window,
		fractol->imag, 0, 0);
}

int	m_zoom(int button, int x, int y, t_fractal *fractol)
{
	double (mouse_real), (mouse_imag);
	double (old_min_real), (old_max_real);
	double (old_min_imag), (old_max_imag);
	old_min_real = fractol->min_real;
	old_max_real = fractol->max_real;
	old_min_imag = fractol->min_imag;
	old_max_imag = fractol->max_imag;
	mouse_real = old_min_real + ((double)x / WIDTH) * (old_max_real
			- old_min_real);
	mouse_imag = old_min_imag + ((double)y / HEIGHT) * (old_max_imag
			- old_min_imag);
	if (button == 4)
		fractol->zoom *= 1.1;
	else if (button == 5)
		fractol->zoom /= 1.1;
	else
		return (0);
	update_bounds(fractol);
	fractol->offset_x += mouse_real - (fractol->min_real + ((double)x / WIDTH)
			* (fractol->max_real - fractol->min_real));
	fractol->offset_y += mouse_imag - (fractol->min_imag + ((double)y / HEIGHT)
			* (fractol->max_imag - fractol->min_imag));
	update_f(fractol);
	return (0);
}
