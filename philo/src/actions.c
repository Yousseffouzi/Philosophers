/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanmazir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 19:58:37 by aanmazir          #+#    #+#             */
/*   Updated: 2025/04/17 13:59:37 by aanmazir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	print_status(t_philosopher *philo, char *status)
{
	pthread_mutex_lock(&philo->shared->write_lock);
	pthread_mutex_lock(&philo->shared->kill_lock);
	if (philo->shared->someone_died)
	{
		pthread_mutex_unlock(&philo->shared->kill_lock);
		pthread_mutex_unlock(&philo->shared->write_lock);
		return (0);
	}
	pthread_mutex_unlock(&philo->shared->kill_lock);
	printf("%ld %d %s\n", get_time_ms() - philo->shared->start_time, philo->id
		+ 1, status);
	pthread_mutex_unlock(&philo->shared->write_lock);
	return (1);
}

int	take_right_first(t_philosopher *philo)
{
	pthread_mutex_lock(philo->right_fork);
	if (!print_status(philo, "has taken a fork"))
	{
		pthread_mutex_unlock(philo->right_fork);
		return (0);
	}
	pthread_mutex_lock(philo->left_fork);
	if (!print_status(philo, "has taken a fork"))
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		return (0);
	}
	return (1);
}

int	take_left_first(t_philosopher *philo)
{
	pthread_mutex_lock(philo->left_fork);
	if (!print_status(philo, "has taken a fork"))
	{
		pthread_mutex_unlock(philo->left_fork);
		return (0);
	}
	pthread_mutex_lock(philo->right_fork);
	if (!print_status(philo, "has taken a fork"))
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		return (0);
	}
	return (1);
}

int	take_forks(t_philosopher *philo)
{
	if (philo->id % 2 == 0)
		usleep(200);
	if (philo->shared->philos < 100)
		usleep(500);
	pthread_mutex_lock(&philo->shared->kill_lock);
	if (philo->shared->someone_died)
	{
		pthread_mutex_unlock(&philo->shared->kill_lock);
		return (0);
	}
	pthread_mutex_unlock(&philo->shared->kill_lock);
	if (philo->id % 2 == 0)
	{
		if (!take_left_first(philo))
			return (0);
	}
	else
	{
		if (!take_right_first(philo))
			return (0);
	}
	return (1);
}
