/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanmazir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:46:22 by aanmazir          #+#    #+#             */
/*   Updated: 2025/04/17 13:52:26 by aanmazir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char *av[])
{
	t_philos	*philo;

	if (ac == 6 || ac == 5)
	{
		if (!args_verified(av))
		{
			printf("Error: arguments problem!\n");
			return (1);
		}
		philo = program_init(av);
		if (!philo)
			return (1);
		philosophers_algo(philo);
		free(philo->forks);
		free(philo);
	}
	else
	{
		printf("Arguments usage not respected\n");
		return (1);
	}
	return (0);
}
