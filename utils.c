/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yofouzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 19:48:18 by yofouzi           #+#    #+#             */
/*   Updated: 2025/04/12 19:48:20 by yofouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(char *s1, char *s2, int n)
{
    if (NULL == s1 || NULL == s2 || n <= 0)
        return (0);
	while (*s1 == *s2 && n > 0 && *s1 != '\0')
	{
		++s1;
		++s2;
        --n;
	}
    return (*s1 - *s2);
}

void    ft_putstr_fd(char *s, int fd)
{
    if (NULL == s || fd < 0)
        return ;
    int     i;

    i = 0;
    while (s[i])
    {
            write(fd, &s[i], 1);
            i++;
    }
}
