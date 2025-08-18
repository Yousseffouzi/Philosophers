/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdahman <abdahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 17:15:35 by abdahman          #+#    #+#             */
/*   Updated: 2025/05/16 13:26:21 by abdahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philosophers(t_data *data)
{
	int	i;

	i = 0;
	data->philos = malloc(sizeof(t_philo) * data->num_philo);
	if (!data->philos)
		return (write(2, "malloc failed for philosophers\n", 32), 1);
	while (i < data->num_philo)
	{
		data->philos[i].id = i;
		data->philos[i].data = data;
		data->philos[i].eating_time = 0;
		data->philos[i].last_eating_time = 0;
		data->philos[i].left_fork = i;
		data->philos[i].right_fork = (i + 1) % data->num_philo;
		if (pthread_mutex_init(&data->philos[i].eating_mutex, NULL) != 0)
			return (write(2, "mutex init failed\n", 19), 1);
		i++;
	}
	return (0);
}

int	init_mutexes(t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philo);
	if (!data->forks)
		return (write(2, "malloc failed for forks\n", 25), 1);
	while (i < data->num_philo)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return (write(2, "mutex init failed\n", 19), 1);
		i++;
	}
	if (pthread_mutex_init(&data->print_mutex, NULL) != 0
		|| pthread_mutex_init(&data->death_mutex, NULL))
		return (write(2, "mutex init failed\n", 19), 1);
	return (0);
}
