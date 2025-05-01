/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanmazir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 19:59:01 by aanmazir          #+#    #+#             */
/*   Updated: 2025/04/17 15:32:03 by aanmazir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_philos	*program_init(char **args)
{
	t_philos	*philo;

	philo = malloc(sizeof(t_philos));
	if (!philo)
	{
		printf("Error: Memory allocation failed.\n");
		return (NULL);
	}
	philo->philos = ft_atoi(args[1]);
	philo->die_time = ft_atoi(args[2]);
	philo->eat_time = ft_atoi(args[3]);
	philo->sleep_time = ft_atoi(args[4]);
	if (args[5])
		philo->meals_nb = ft_atoi(args[5]);
	else
		philo->meals_nb = -1;
	philo->someone_died = 0;
	philo->forks = malloc(sizeof(pthread_mutex_t) * philo->philos);
	if (!philo->forks)
	{
		free(philo);
		printf("Error: Memory allocation failed.\n");
		return (NULL);
	}
	return (philo);
}
