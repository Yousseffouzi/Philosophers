/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yofouzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 21:34:03 by yofouzi           #+#    #+#             */
/*   Updated: 2025/04/14 01:34:49 by yofouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	data_init(t_fractal *fractal)
{
	fractal->color_mode = 0;
	fractal->zoom = 1.0;
	fractal->min_real = -2.0;
	fractal->max_real = 2.0;
	fractal->min_imag = -2.0;
	fractal->max_imag = 2.0;
	fractal->offset_x = 0.0;
	fractal->offset_y = 0.0;
	fractal->c_real = 0.0;
	fractal->c_img = 0.0;
	fractal->name = 0;
	fractal->max_iter = 50;
}

void	init_fractol(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (fractal->mlx_connection == NULL)
		exit(EXIT_FAILURE);
	fractal->window = mlx_new_window(fractal->mlx_connection, WIDTH, HEIGHT,
			"Fractol");
	if (fractal->window == NULL)
	{
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		exit(EXIT_FAILURE);
	}
	fractal->imag = mlx_new_image(fractal->mlx_connection, WIDTH, HEIGHT);
	if (fractal->imag == NULL)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->window);
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		exit(EXIT_FAILURE);
	}
	fractal->addr = mlx_get_data_addr(fractal->imag, &fractal->bpp,
			&fractal->line_len, &fractal->endian);
	data_init(fractal);
}
