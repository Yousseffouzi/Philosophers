/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yofouzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 01:18:11 by yofouzi           #+#    #+#             */
/*   Updated: 2025/04/14 01:18:14 by yofouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_color(int iter, int max_iter, t_fractal *fractol)
{
	if (iter == max_iter)
		return (0x000000);

	int r, g, b;

	if (fractol->color_mode == 0)
	{
		r = (iter * 4) % 256;
		g = (iter * 23) % 256;
		b = (iter * 19) % 256;
	}
	else if (fractol->color_mode == 1)
	{
		r = (iter * 25) % 256;
		g = (iter * 50) % 256;
		b = (iter * 100) % 256;
	}
	else if (fractol->color_mode == 2)
	{
		r = (iter * 255) % 256;
		g = (iter * 94) % 256;
		b = (iter * 77) % 256;
	}
	else if (fractol->color_mode == 3)
	{
		r = (iter * 3) % 256;
		g = (iter * 13) % 256;
		b = (iter * 17) % 256;
	}
	else if (fractol->color_mode == 4)
	{
		r = (iter * 21) % 256;
		g = (iter * 11) % 256;
		b = (iter * 3) % 256;
	}
	else if (fractol->color_mode == 5)
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



int	key_hook(int keycode, t_fractal *fractol)
{
	double		move_amount = 0.2 / fractol->zoom;

	if (keycode == 65307)
	{
        mlx_destroy_image(fractol->mlx_connection, fractol->imag);
		mlx_destroy_window(fractol->mlx_connection, fractol->window);
		mlx_destroy_display(fractol->mlx_connection);
		free(fractol->mlx_connection);
		exit(0);
	}
	else if (keycode == 32)
		fractol->color_mode = (fractol->color_mode + 1) % 10;
	else if (keycode == 65361) // Left arrow
		fractol->offset_x -= move_amount;
	else if (keycode == 65363) // Right arrow
		fractol->offset_x += move_amount;
	else if (keycode == 65362) // Up arrow
		fractol->offset_y -= move_amount;
	else if (keycode == 65364) // Down arrow
		fractol->offset_y += move_amount;
	update_f(fractol); // Redraw fractal after movement
	return (0);
}

int	close_window(t_fractal *fractol)
{
    mlx_destroy_image(fractol->mlx_connection,fractol->imag);
    mlx_destroy_window(fractol->mlx_connection, fractol->window);
    mlx_destroy_display(fractol->mlx_connection);
    free(fractol->mlx_connection);
	exit(1);
}

