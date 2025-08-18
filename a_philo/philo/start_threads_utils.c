/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_threads_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdahman <abdahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 19:27:58 by abdahman          #+#    #+#             */
/*   Updated: 2025/05/18 18:56:11 by abdahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	help_philosopher(t_philo *philo, t_data *data)
{
	if (philo->id % 2 != 0)
		usleep(100);
	while (1)
	{
		pthread_mutex_lock(&data->death_mutex);
		if (data->someone_died)
		{
			pthread_mutex_unlock(&data->death_mutex);
			break ;
		}
		pthread_mutex_unlock(&data->death_mutex);
		print_message(philo, "is thinking");
		take_forks(philo);
		if (eat(philo))
			return ;
		print_message(philo, "is sleeping");
		usleep(data->sleep_time * 1000);
	}
}

void	*philosopher_routine(void *arg)
{
	t_philo		*philo;
	t_data		*data;

	philo = (t_philo *)arg;
	data = philo->data;
	if (data->num_philo == 1)
	{
		pthread_mutex_lock(&data->forks[philo->left_fork]);
		print_message(philo, "has taken a left fork");
		usleep(data->time_to_die * 1000);
		pthread_mutex_unlock(&data->forks[philo->left_fork]);
		return (NULL);
	}
	help_philosopher(philo, data);
	return (NULL);
}

int	check_philo_death(t_data *data, int i)
{
	long long	current_time;

	current_time = get_time();
	pthread_mutex_lock(&data->philos[i].eating_mutex);
	if ((current_time - data->philos[i].last_eating_time) > data->time_to_die)
	{
		pthread_mutex_unlock(&data->philos[i].eating_mutex);
		pthread_mutex_lock(&data->death_mutex);
		data->someone_died = 1;
		pthread_mutex_unlock(&data->death_mutex);
		pthread_mutex_lock(&data->print_mutex);
		printf("%lld %d -died-\n", current_time - data->start_time,
			data->philos[i].id + 1);
		pthread_mutex_unlock(&data->print_mutex);
		return (1);
	}
	pthread_mutex_unlock(&data->philos[i].eating_mutex);
	return (0);
}

void	*monitor_routine(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
	while (1)
	{
		i = 0;
		while (i < data->num_philo)
		{
			if (check_philo_death(data, i))
				return (NULL);
			i++;
		}
		if (data->num_time_to_eat > 0)
		{
			if (data->end_eating >= data->num_philo)
				return (NULL);
		}
		usleep(1000);
	}
	return (NULL);
}
