/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhoussi <ykhoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 04:27:51 by ykhoussi          #+#    #+#             */
/*   Updated: 2025/04/11 22:38:57 by ykhoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	error_message(void)
{
	write(2, "Error: Invalid input or initialization failed.\n", 48);
	write(2, "Usage: ./fractol [fractol_name]\n", 33);
	write(2, "Available fractals: mandelbrot\n", 32);
	write(2, "Available fractals: julia <set> <set>\n", 39);
	exit(1);
}

int	failed(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	error_message();
	exit(1);
}
