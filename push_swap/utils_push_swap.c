/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <yofouzi@student.1337.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 07:37:28 by root              #+#    #+#             */
/*   Updated: 2025/04/07 07:37:31 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(const char *nb, char **args, t_list **a)
{
	int		i;
	int		j;
	long	k;

	i = 0;
	j = 1;
	k = 0;
	while ((nb[i] == 32) || (nb[i] >= 9 && nb[i] <= 13))
		i++;
	if (nb[i] == '+' || nb[i] == '-')
	{
		if (nb[i] == '-')
			j *= -1;
		i++;
	}
	while (nb[i] >= 48 && nb[i] <= 57)
	{
		k = k * 10 + (nb[i] - 48);
		i++;
	}
	if ((k * j) >= 2147483647 || (k * j) <= -2147483648)
		ft_error(a, args);
	return (j * k);
}

int	ft_checkargs(char *av)
{
	int	i;
	int	f;

	i = 0;
	f = 0;
	while (av[i])
	{
		if (!((av[i] >= '0' && av[i] <= '9') || av[i] == ' ' || av[i] == '+'
				|| av[i] == '-'))
			return (0);
		if ((av[i] >= '0' && av[i] <= '9'))
			f = 1;
		if (av[i] == '+' || av[i] == '-')
		{
			if (i)
			{
				if (av[i - 1] != ' ')
					return (0);
			}
			if (!(av[i + 1] >= '0' && av[i + 1] <= '9'))
				return (0);
		}
		i++;
	}
	return (f);
}

void	fill_stack(t_list **a, char **av)
{
	t_list	*new;
	int		i;
	int		j;
	char	**arg;

	j = 1;
	while (av[j])
	{
		if (!ft_checkargs(av[j]))
			(ft_lstclear(a), write(2, "Error\n", 6), exit(1));
		arg = ft_split(av[j], ' ');
		i = 0;
		while (arg[i])
		{
			if (!(new = ft_lstnew(ft_atoi(arg[i], arg, a))))
				ft_error(a, arg);
			ft_lstadd_back(a, new);
			if (check_dup(*a) == 0)
				ft_error(a, arg);
			i++;
		}
		ft_free(arg);
		j++;
	}
}
