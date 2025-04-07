/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <yofouzi@student.1337.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 07:21:55 by root              #+#    #+#             */
/*   Updated: 2025/04/07 07:21:58 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list *a;
	t_list *b;
	t_list *trash;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	fill_stack(&a, av);
	if (check_sort(a) == 1)
	{
		ft_lstclear(&a);
		return (0);
	}
	if (ft_lstsize(a) <= 3)
		sort_3(&a);
	else if (ft_lstsize(a) <= 5)
		sort_5(&a, &b);
	else
		sort_all(&a, &b, sorted(a), ft_lstsize(a));
	while (a)
	{
		trash = a;
		a = a->next;
		free(trash);
	}
}