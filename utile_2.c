/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhoussi <ykhoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:30:53 by ykhoussi          #+#    #+#             */
/*   Updated: 2025/04/12 16:16:20 by ykhoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	get_color(int iter, int max_iter, t_data *data)
{
	if (iter == max_iter)
		return (0x000000);

	int r, g, b;

	if (data->color_mode == 0)
	{
		r = (iter * 4) % 256;
		g = (iter * 23) % 256;
		b = (iter * 19) % 256;
	}
	else if (data->color_mode == 1)
	{
		r = (iter * 25) % 256;
		g = (iter * 50) % 256;
		b = (iter * 100) % 256;
	}
	else if (data->color_mode == 2)
	{
		r = (iter * 255) % 256;
		g = (iter * 94) % 256;
		b = (iter * 77) % 256;
	}
	else if (data->color_mode == 3)
	{
		r = (iter * 3) % 256;
		g = (iter * 13) % 256;
		b = (iter * 17) % 256;
	}
	else if (data->color_mode == 4)
	{
		r = (iter * 21) % 256;
		g = (iter * 11) % 256;
		b = (iter * 3) % 256;
	}
	else if (data->color_mode == 5)
	{
		r = (iter * 200) % 256;
		g = (iter * 50) % 256;
		b = (iter * 255) % 256;
	}
	else if (data->color_mode == 6)
	{
		r = (iter * 12) % 256;
		g = (iter * 5) % 256;
		b = (iter * 20) % 256;
	}
	else if (data->color_mode == 7)
	{
		r = (iter * 17) % 256;
		g = (iter * 2) % 256;
		b = (iter * 29) % 256;
	}
	else if (data->color_mode == 8)
	{
		r = (iter * 30) % 256;
		g = (iter * 15) % 256;
		b = (iter * 10) % 256;
	}
	else
	{
		r = (iter * 18) % 256;
		g = (iter * 28) % 256;
		b = (iter * 6) % 256;
	}

	return ((r << 16) | (g << 8) | b);
}



int	key_hook(int keycode, t_data *data)
{
	double		move_amount = 0.2 / data->zoom;

	if (keycode == 65307)
	{
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_image(data->mlx, data->img);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit(0);
	}
	else if (keycode == 32)
		data->color_mode = (data->color_mode + 1) % 10;
	else if (keycode == 65361) // Left arrow
		data->offset_x -= move_amount;
	else if (keycode == 65363) // Right arrow
		data->offset_x += move_amount;
	else if (keycode == 65362) // Up arrow
		data->offset_y -= move_amount;
	else if (keycode == 65364) // Down arrow
		data->offset_y += move_amount;
	update_f(data); // Redraw fractal after movement
	return (0);
}

int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}
