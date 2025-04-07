/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <yofouzi@student.1337.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 08:43:07 by root              #+#    #+#             */
/*   Updated: 2025/04/07 08:43:10 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	x;

	x = *a;
	*a = *b;
	*b = x;
}

int	*sort_arr(int *arr, int size)
{
	int	j;
	int	i;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		if (arr[j] < arr[i])
		{
			ft_swap(&arr[j], &arr[i]);
			i = 0;
		}
		else
			i++;
	}
	return (arr);
}

int	*sorted(t_list *a)
{
	int	*arr;
	int	i;
	int	j;

	i = 0;
	j = ft_lstsize(a);
	if (!(arr = malloc(sizeof(int) * j)))
		return (NULL);
	while (a)
	{
		arr[i] = a->content;
		a = a->next;
		i++;
	}
	arr = sort_arr(arr, j);
	return (arr);
}
