/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdahman <abdahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 11:51:59 by abdahman          #+#    #+#             */
/*   Updated: 2025/05/18 18:52:02 by abdahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	init_philo(t_data *data)
{
	int	i;

	i = 0;
	data->philo = malloc(sizeof(t_philo) * data->num_philo);
	if (!data->philo)
		return (printf("philo malloc filed"), 1);
	while (i < data->num_philo)
	{
		data->philo[i].id = i;
		data->philo[i].data = data;
		data->philo[i].last_time_to_eat = 0;
		data->philo[i].time_to_eat = 0;
		i++;
	}
	return (0);
}

int	init_semaphore(t_data *data)
{
	sem_unlink("/forks");
	sem_unlink("/print");
	sem_unlink("/died");
	sem_unlink("/eat");
	sem_unlink("/access");
	sem_unlink("/end_eating");
	sem_unlink("/check");
	sem_unlink("/done");
	data->fork = sem_open("/forks", O_CREAT, 0644, data->num_philo);
	data->deid = sem_open("/died", O_CREAT, 0644, 1);
	data->print = sem_open("/print", O_CREAT, 0664, 1);
	data->eat = sem_open("/eat", O_CREAT, 0644, 1);
	data->access = sem_open("/access", O_CREAT, 0644, data->num_philo / 2);
	data->end_eating = sem_open("/end_eating", O_CREAT, 0644, 0);
	data->check = sem_open("/check", O_CREAT, 0644, 0);
	if (data->fork == SEM_FAILED || data->print == SEM_FAILED
		|| data->deid == SEM_FAILED || data->eat == SEM_FAILED
		|| data->end_eating == SEM_FAILED || data->access == SEM_FAILED
		|| data->check == SEM_FAILED)
	{
		perror("sem_open failed");
		return (1);
	}
	return (0);
}
