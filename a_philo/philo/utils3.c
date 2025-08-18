/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdahman <abdahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 17:18:44 by abdahman          #+#    #+#             */
/*   Updated: 2025/05/18 18:11:45 by abdahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *philo)
{
	if (philo->id % 2 != 0)
	{
		pthread_mutex_lock(&philo->data->forks[philo->left_fork]);
		print_message(philo, "has taken a left fork");
		pthread_mutex_lock(&philo->data->forks[philo->right_fork]);
		print_message(philo, "has taken a right fork");
	}
	else
	{
		pthread_mutex_lock(&philo->data->forks[philo->right_fork]);
		print_message(philo, "has taken a right fork");
		pthread_mutex_lock(&philo->data->forks[philo->left_fork]);
		print_message(philo, "has taken a left fork");
	}
}

int	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->eating_mutex);
	philo->eating_time++;
	philo->last_eating_time = get_time();
	pthread_mutex_unlock(&philo->eating_mutex);
	print_message(philo, "is eating");
	usleep(philo->data->eat_time * 1000 - 500);
	pthread_mutex_unlock(&philo->data->forks[philo->right_fork]);
	pthread_mutex_unlock(&philo->data->forks[philo->left_fork]);
	if (philo->data->num_time_to_eat > 0)
	{
		if (philo->eating_time >= philo->data->num_time_to_eat)
		{
			philo->data->end_eating++;
			return (1);
		}
	}
	return (0);
}
