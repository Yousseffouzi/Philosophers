/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhoussi <ykhoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 00:07:13 by ykhoussi          #+#    #+#             */
/*   Updated: 2025/04/11 22:49:23 by ykhoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	init_julia(t_data *data, char *s, char *s2)
{
	double (real), (imag);
	*data = init_mlx_window();
	real = ft_atof(s, data);
	imag = ft_atof(s2, data);
	data->fractal_type = 1;
	julia(data, real, imag);
}

void	execute_mandelbrot(t_data *data)
{
	*data = init_mlx_window();
	data->fractal_type = 0;
	mandelbrot(data);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 2)
	{
		if (!ft_strcmp(av[1], "mandelbrot"))
			execute_mandelbrot(&data);
		else
			error_message();
	}
	else if (ac == 4)
	{
		if (!ft_strcmp(av[1], "julia"))
			init_julia(&data, av[2], av[3]);
	}
	else
		error_message();
	mlx_key_hook(data.win, key_hook, &data);
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_mouse_hook(data.win, m_zoom, &data);
	mlx_loop(data.mlx);
}
