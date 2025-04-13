/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhoussi <ykhoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 05:56:56 by ykhoussi          #+#    #+#             */
/*   Updated: 2025/04/12 16:16:32 by ykhoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

t_data	init_mlx_window(void)
{
	t_data	data;

	data.mlx = mlx_init();
	if (!data.mlx)
		exit(EXIT_FAILURE);
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Fractol");
	if (!data.win)
		exit(EXIT_FAILURE);
	data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	if (!data.img)
		exit(EXIT_FAILURE);
	data.addr = mlx_get_data_addr(data.img,
			&data.bits_per_pixel, &data.line_length, &data.endian);
	data.min_real = -2.0;
	data.max_real = 2.0;
	data.min_imag = -2.0;
	data.max_imag = 2.0;
	data.zoom = 1.0;
	data.max_iter = 50;
	data.color_mode = 0;
	return (data);
}
