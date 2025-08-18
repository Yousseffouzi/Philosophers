/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_process_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdahman <abdahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 13:23:13 by abdahman          #+#    #+#             */
/*   Updated: 2025/05/18 14:09:10 by abdahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*monitor_routine(void *arg)
{
	t_philo		*philo;
	long long	time;

	philo = (t_philo *)arg;
	while (1)
	{
		usleep(1000);
		sem_wait(philo->data->eat);
		time = get_time();
		if (time - philo->last_time_to_eat > philo->data->time_to_die)
		{
			sem_wait(philo->data->deid);
			sem_wait(philo->data->print);
			printf("%lld %d -\033[0;31mdied\033[0m-\n",
				time - philo->data->start_time, philo->id + 1);
			sem_post(philo->data->deid);
			sem_post(philo->data->eat);
			sem_post(philo->data->check);
			return (NULL);
		}
		sem_post(philo->data->eat);
	}
	return (NULL);
}

void	philo_help(t_philo *philo)
{
	if (philo->id % 2 != 0)
		usleep(500);
	while (1)
	{
		sem_wait(philo->data->access);
		print_message(philo, "is thinking\n");
		sem_wait(philo->data->fork);
		print_message(philo, "has taken a first fork\n");
		sem_wait(philo->data->fork);
		print_message(philo, "has taken a second fork\n");
		eat(philo);
		print_message(philo, "is sleeping\n");
		usleep(philo->data->sleep_time * 1000);
	}
}

void	philo_rotine(t_philo philo)
{
	pthread_t	monitor;

	if (philo.data->num_philo == 1)
	{
		print_message(&philo, "has taken a fork\n");
		usleep(philo.data->time_to_die * 1000);
		print_message(&philo, "-\033[0;31mdied\033[0m-\n");
		exit(1);
	}
	if (pthread_create(&monitor, NULL, monitor_routine, &philo) != 0)
		return ;
	pthread_detach(monitor);
	philo_help(&philo);
	return ;
}
