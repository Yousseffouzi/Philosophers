/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yofouzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 19:47:58 by yofouzi           #+#    #+#             */
/*   Updated: 2025/04/12 19:48:00 by yofouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
//#include </home/yofouzi/Desktop/minilibx-linux/mlx.h>
#include <minilibx-linux/mlx.h>

//struct to the img;
typedef struct s_img;
{
    void    *img;
}               t_img


//utils
int	ft_strncmp(char *s1, char *s2, int n);
void    ft_putstr_fd(char *s, int fd);


#endif
