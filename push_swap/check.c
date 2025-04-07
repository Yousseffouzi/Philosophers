/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <yofouzi@student.1337.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 08:16:12 by root              #+#    #+#             */
/*   Updated: 2025/04/07 08:16:13 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(t_list *a)
{
	while (a->next)
	{
		if (a->content > a->next->content)
			return (0);
		a = a->next;
	}
	return (1);
}

int	check_dup(t_list *a)
{
	t_list	*check;

	while (a->next)
	{
		check = a->next;
		while (check)
		{
			if (a->content == check->content)
				return (0);
			check = check->next;
		}
		a = a->next;
	}
	return (1);
}

void	ft_error(t_list **a, char **av)
{
	write(2, "Error\n", 6);
	ft_free(av);
	ft_lstclear(a);
	exit(1);
}
