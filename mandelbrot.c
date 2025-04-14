/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yofouzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 01:56:36 by yofouzi           #+#    #+#             */
/*   Updated: 2025/04/14 01:56:39 by yofouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot_iteration(double real, double img, int max_iter)
{
	int	iter;

	double(z_real), (z_img), (tmp);
	z_real = 0.0;
	z_img = 0.0;
	tmp = 0.0;
	iter = 0;
	while ((z_real * z_real + z_img * z_img < 4) && iter < max_iter)
	{
		tmp = z_real * z_real - z_img * z_img + real;
		z_img = 2 * z_real * z_img + img;
		z_real = tmp;
		iter++;
	}
	return (iter);
}

void	my_pixel_put(t_fractal *fractol, int x, int y, int color)
{
	char	*dst;

	dst = fractol->addr + (y * fractol->line_len + x * (fractol->bpp / 8));
	*(unsigned int *)dst = color;
}

void	mandelbrot(t_fractal *fractol)
{
	int x, y, iter, color;
	double real, imag;
	iter = 0;
	color = 0;
	real = 0.0;
	imag = 0.0;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			real = (fractol->min_real) + ((double)x / WIDTH)
				* (fractol->max_real - fractol->min_real);
			imag = (fractol->min_imag) + ((double)y / HEIGHT)
				* (fractol->max_imag - fractol->min_imag);
			iter = mandelbrot_iteration(real, imag, fractol->max_iter);
			color = get_color(iter, fractol->max_iter, fractol);
			my_pixel_put(fractol, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx_connection, fractol->window,
		fractol->imag, 0, 0);
}
