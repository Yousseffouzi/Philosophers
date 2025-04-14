/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yofouzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 20:40:08 by yofouzi           #+#    #+#             */
/*   Updated: 2025/04/13 20:40:10 by yofouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 50

typedef struct s_fractal
{
	void	*mlx_connection;
	void	*window;
	void	*imag;
	char	*addr;
	int bpp; // bits per pixel
	int		endian;
	int		line_len;
	int		name;
	int		color_mode;
	int		max_iter;
	double	zoom;
	double	offset_x;
	double	offset_y;
	double	min_real;
	double	max_real;
	double	min_imag;
	double	max_imag;
	double	c_real;
	double	c_img;
}			t_fractal;

// main function
void		init_mandelbrot(t_fractal *fractal);
void		init_julia(t_fractal *fractal, char *s1, char *s2);

// init
void		init_fractol(t_fractal *fractal);

// utils;
int			ft_strncmp(char *s1, char *s2, int n);
void		ft_putstr_fd(char *s, int fd);
double		ft_atof(const char *str, t_fractal *fractol);
void		error_message(void);
int			failed(t_fractal *fractol);

// hooks colors keyscode
int			get_color(int iter, int max_iter, t_fractal *fractol);
int			close_window(t_fractal *fractol);
int			key_hook(int keycode, t_fractal *fractol);

// draw 1 mandelbrot
int			mandelbrot_iteration(double real, double img, int max_iter);
void		my_pixel_put(t_fractal *fractal, int x, int y, int color);
void		mandelbrot(t_fractal *fractol);
void		julia(t_fractal *fractol, double real, double img);

// m_zoom
int			m_zoom(int button, int x, int y, t_fractal *fractol);
void		update_f(t_fractal *fractol);
void		update_bounds(t_fractal *fractol);

#endif
