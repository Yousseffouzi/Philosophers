/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_verification.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanmazir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 19:59:22 by aanmazir          #+#    #+#             */
/*   Updated: 2025/04/17 14:01:29 by aanmazir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	args_verified(char **args)
{
	int	i;
	int	j;

	i = 1;
	while (args[i])
	{
		j = 0;
		while (args[i][j] != '\0')
		{
			if (!ft_isdigit(args[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	if (ft_atoi(args[1]) <= 0)
		return (0);
	if (ft_atoi(args[2]) <= 0 || ft_atoi(args[3]) <= 0 || ft_atoi(args[4]) <= 0)
		return (0);
	if (args[5] && ft_atoi(args[5]) == 0)
		exit(0);
	return (1);
}
