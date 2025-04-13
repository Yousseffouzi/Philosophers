/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhoussi <ykhoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 06:40:58 by ykhoussi          #+#    #+#             */
/*   Updated: 2025/04/11 21:32:09 by ykhoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	julia_iter(double z_real, double z_img, double c_real, double c_img)
{
	int		iter;
	double	tmp;

	iter = 0;
	while ((z_real * z_real + z_img * z_img < 4) && iter < MAX_ITER)
	{
		tmp = z_real * z_real - z_img * z_img + c_real;
		z_img = 2 * z_real * z_img + c_img;
		z_real = tmp;
		iter++;
	}
	return (iter);
}

void	julia(t_data *data, double real, double imag)
{
	int (x), (y), (iter), (color);
	double (z_real), (z_imag);
	data->c_real = real;
	data->c_img = imag;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			z_real = data->min_real + ((double)x / WIDTH)
				* (data->max_real - data->min_real);
			z_imag = data->min_imag + ((double)y / HEIGHT)
				* (data->max_imag - data->min_imag);
			iter = julia_iter(z_real, z_imag, data->c_real, data->c_img);
			color = get_color(iter, data->max_iter, data);
			my_pixel_put(data, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
