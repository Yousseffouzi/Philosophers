/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <yofouzi@student.1337.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 09:15:19 by root              #+#    #+#             */
/*   Updated: 2025/04/07 09:15:21 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_plstlast(t_list *lst)
{
	if (!lst || !lst->next)
		return (NULL);
	while (lst->next->next)
		lst = lst->next;
	return (lst);
}

void	r_rotate(t_list **t)
{
	t_list	*st;
	t_list	*last;
	t_list	*plast;

	if (!*t || !(*t)->next)
		return ;
	st = *t;
	last = ft_lstlast(*t);
	plast = ft_plstlast(*t);
	last->next = st;
	plast->next = NULL;
	*t = last;
}

void	rra(t_list **a, int flag)
{
	r_rotate(a);
	if (flag == 0)
		write(1, "rra\n", 4);
}

void	rrb(t_list **b, int flag)
{
	r_rotate(b);
	if (flag == 0)
		write(1, "rrb\n", 4);
}

void	rrr(t_list **a, t_list **b, int flag)
{
	r_rotate(a);
	r_rotate(b);
	if (flag == 0)
		write(1, "rrr\n", 4);
}
