/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <yofouzi@student.1337.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:38:16 by root              #+#    #+#             */
/*   Updated: 2025/04/07 11:38:18 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_range(t_list **a)
{
	if (ft_lstsize(*a) <= 18)
		return (3);
	else if (ft_lstsize(*a) <= 100)
		return (6);
	else if (ft_lstsize(*a) <= 500)
		return (12);
	else
		return (18);
}

void	range_up(int *s, int *e, int size)
{
	if (*s < *e)
		*s += 1;
	if (*e < size - 1)
		*e += 1;
}

int	ft_lstendex(t_list *b, int n)
{
	int	i;

	i = 0;
	while (b)
	{
		if (b->content == n)
			return (i);
		i++;
		b = b->next;
	}
	return (-1);
}

void	back_to_a(t_list **a, t_list **b, int *arr, int e)
{
	int	i;

	i = ft_lstsize(*b);
	while (*b)
	{
		if ((*b)->content == arr[e])
		{
			pa(a, b, 0);
			e--;
			i = ft_lstsize(*b);
		}
		else if (ft_lstendex(*b, arr[e]) <= (i / 2))
			rb(b, 0);
		else
			rrb(b, 0);
	}
	free(arr);
}

void	sort_all(t_list **a, t_list **b, int *arr, int size)
{
	int	rang;
	int	s;
	int	e;

	rang = size / get_range(a);
	s = 0;
	e = rang;
	while (*a)
	{
		if ((*a)->content <= arr[s])
		{
			pb(a, b, 0);
			if ((*b)->next != NULL)
				rb(b, 0);
			range_up(&s, &e, size);
		}
		else if ((*a)->content <= arr[e])
		{
			pb(a, b, 0);
			range_up(&s, &e, size);
		}
		else
			ra(a, 0);
	}
	back_to_a(a, b, arr, e);
}
