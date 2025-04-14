/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yofouzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 01:57:34 by yofouzi           #+#    #+#             */
/*   Updated: 2025/04/14 01:57:37 by yofouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia_iter(double z_real, double z_img, double c_real, double c_img)
{
	int		iter;
	double	tmp;

	iter = 0;
    tmp = 0.0;
	while ((z_real * z_real + z_img * z_img < 4) && iter < MAX_ITER)
	{
		tmp = z_real * z_real - z_img * z_img + c_real;
		z_img = 2 * z_real * z_img + c_img;
		z_real = tmp;
		iter++;
	}
	return (iter);
}


void    julia(t_fractal *fractol, double real, double img)
{
    int (x), (y), (iter), (color);
	double (z_real), (z_imag);

    fractol->c_real = real;
    fractol->c_img = img;
    z_real = 0.0;
    z_imag = 0.0;
    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while(x < WIDTH)
        {
            z_real = (fractol->min_real) + ((double)x / WIDTH)
                * (fractol->max_real - fractol->min_real);
            z_imag = (fractol->min_imag) + ((double)y /HEIGHT)
                * (fractol->max_imag - fractol->min_imag);
            iter = julia_iter(z_real, z_imag, fractol->c_real, fractol->c_img);
            color = get_color(iter, fractol->max_iter, fractol);
            my_pixel_put(fractol, x, y, color);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(fractol->mlx_connection, fractol->window, fractol->imag, 0, 0);
}
