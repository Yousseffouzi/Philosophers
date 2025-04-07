/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <yofouzi@student.1337.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 09:01:58 by root              #+#    #+#             */
/*   Updated: 2025/04/07 09:02:01 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **x, t_list **y)
{
	t_list	*stx;
	t_list	*sty;

	if (!x || !*x)
		return ;
	stx = *x;
	sty = *y;
	*x = stx->next;
	*y = stx;
	stx->next = sty;
}

void	pa(t_list **a, t_list **b, int flag)
{
	push(b, a);
	if (flag == 0)
		write(1, "pa\n", 3);
}

void	pb(t_list **a, t_list **b, int flag)
{
	push(a, b);
	if (flag == 0)
		write(1, "pb\n", 3);
}
