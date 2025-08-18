/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_monitor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanmazir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 19:58:45 by aanmazir          #+#    #+#             */
/*   Updated: 2025/05/01 13:07:31 by aanmazir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	announce_death(t_philosopher *philosopher, long current_time)
{
	pthread_mutex_unlock(&philosopher->shared->death_lock);
	pthread_mutex_lock(&philosopher->shared->write_lock);
	printf("%ld %d died\n",
		current_time - philosopher->shared->start_time,
		philosopher->id + 1);
	pthread_mutex_unlock(&philosopher->shared->write_lock);
	pthread_mutex_lock(&philosopher->shared->kill_lock);
	philosopher->shared->someone_died = 1;
	pthread_mutex_unlock(&philosopher->shared->kill_lock);
}

int	check_philosopher_death(t_philosopher *philosophers, int i,
		long current_time)
{
	pthread_mutex_lock(&philosophers[0].shared->death_lock);
	if ((current_time
			- philosophers[i].last_meal_time) > philosophers[i].die_time)
	{
		announce_death(&philosophers[i], current_time);
		return (1);
	}
	if (philosophers[i].phn != -1
		&& philosophers[i].meals_eaten >= philosophers[i].phn)
	{
		pthread_mutex_unlock(&philosophers[0].shared->death_lock);
		return (0);
	}
	pthread_mutex_unlock(&philosophers[0].shared->death_lock);
	return (0);
}

int	all_philosophers_done(t_philosopher *philosophers)
{
	int	i;

	i = 0;
	while (i < philosophers[0].shared->philos)
	{
		pthread_mutex_lock(&philosophers[0].shared->death_lock);
		if (philosophers[i].meals_eaten < philosophers[i].phn)
		{
			pthread_mutex_unlock(&philosophers[0].shared->death_lock);
			return (0);
		}
		pthread_mutex_unlock(&philosophers[0].shared->death_lock);
		i++;
	}
	return (1);
}

void	*death_monitor(void *arg)
{
	t_philosopher	*philosophers;
	long			current_time;
	int				i;

	philosophers = (t_philosopher *)arg;
	while (1)
	{
		i = 0;
		while (i < philosophers[0].shared->philos)
		{
			current_time = get_time_ms();
			if (check_philosopher_death(philosophers, i, current_time))
				return (NULL);
			i++;
		}
		if (philosophers[0].phn != -1 && all_philosophers_done(philosophers))
			return (NULL);
	}
	return (NULL);
}
