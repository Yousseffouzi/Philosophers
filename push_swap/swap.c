/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <yofouzi@student.1337.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 08:53:25 by root              #+#    #+#             */
/*   Updated: 2025/04/07 08:53:26 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **t)
{
	t_list	*st;
	t_list	*nd;

	if (!*t || !(*t)->next)
		return ;
	st = *t;
	nd = st->next;
	st->next = nd->next;
	nd->next = st;
	*t = nd;
}

void	sa(t_list **a, int flag)
{
	swap(a);
	if (flag == 0)
		write(1, "sa\n", 3);
}

void	sb(t_list **b, int flag)
{
	swap(b);
	if (flag == 0)
		write(1, "sb\n", 3);
}

void	ss(t_list **a, t_list **b, int flag)
{
	swap(a);
	swap(b);
	if (flag == 0)
		write(1, "ss\n", 3);
}