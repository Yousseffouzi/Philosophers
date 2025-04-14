/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yofouzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 20:39:07 by yofouzi           #+#    #+#             */
/*   Updated: 2025/04/13 20:39:10 by yofouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mandelbrot(t_fractal *fractal)
{
	init_fractol(fractal);
	fractal->name = 1;
	mandelbrot(fractal);
}

void	init_julia(t_fractal *fractal, char *s1, char *s2)
{
	double	real;
	double	i;

	real = 0.0;
	i = 0.0;
	init_fractol(fractal);
	real = ft_atof(s1, fractal);
	i = ft_atof(s2, fractal);
	fractal->name = 2;
	julia(fractal, real, i);
}

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if (ac == 2)
	{
		if (!ft_strncmp(av[1], "mandelbrot", 10))
			init_mandelbrot(&fractal);
		else
			error_message();
	}
	else if (ac == 4)
	{
		if (!ft_strncmp(av[1], "julia", 5))
			init_julia(&fractal, av[2], av[3]);
		else
			error_message();
	}
	else
		error_message();
	mlx_key_hook(fractal.window, key_hook, &fractal);
	mlx_hook(fractal.window, 17, 0, close_window, &fractal);
	mlx_mouse_hook(fractal.window, m_zoom, &fractal);
	mlx_loop(fractal.mlx_connection);
}
