/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhoussi <ykhoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:48:45 by ykhoussi          #+#    #+#             */
/*   Updated: 2025/04/11 23:30:08 by ykhoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	update_bounds(t_data *data)
{
	data->min_real = -2.0 / data->zoom + data->offset_x;
	data->max_real = 2.0 / data->zoom + data->offset_x;
	data->min_imag = -2.0 / data->zoom + data->offset_y;
	data->max_imag = 2.0 / data->zoom + data->offset_y;
}

void	update_f(t_data *data)
{
	update_bounds(data);
	if (data->fractal_type == 0)
		mandelbrot(data);
	else if (data->fractal_type == 1)
		julia(data, data->c_real, data->c_img);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

int	m_zoom(int button, int x, int y, t_data *data)
{
	double (mouse_real), (mouse_imag);
	double (old_min_real), (old_max_real);
	double (old_min_imag), (old_max_imag);
	old_min_real = data->min_real;
	old_max_real = data->max_real;
	old_min_imag = data->min_imag;
	old_max_imag = data->max_imag;
	mouse_real = old_min_real + ((double)x / WIDTH)
		* (old_max_real - old_min_real);
	mouse_imag = old_min_imag
		+ ((double)y / HEIGHT) * (old_max_imag - old_min_imag);
	if (button == 4)
		data->zoom *= 1.1;
	else if (button == 5)
		data->zoom /= 1.1;
	else
		return (0);
	update_bounds(data);
	data->offset_x += mouse_real - (data->min_real
			+ ((double)x / WIDTH) * (data->max_real - data->min_real));
	data->offset_y += mouse_imag - (data->min_imag
			+ ((double)y / HEIGHT) * (data->max_imag - data->min_imag));
	update_f(data);
	return (0);
}

