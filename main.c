/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yofouzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 19:48:08 by yofouzi           #+#    #+#             */
/*   Updated: 2025/04/12 19:48:11 by yofouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(int ac, char **av)
{
    if((ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10)) ||
        (ac == 4 && !ft_strncmp(av[1], "julia", 5)))
        //code;
    else
    {
        ft_putstr_fd("Please enter \n\t\"./fractol mandelbrot\" or \n\t\"./fractol julia <value_1> <value_2>\"\n", 2);
        exit(1);
    }
}
