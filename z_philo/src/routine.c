/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanmazir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 19:59:07 by aanmazir          #+#    #+#             */
/*   Updated: 2025/04/13 19:59:09 by aanmazir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	check_d(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->shared->kill_lock);
	if (philo->shared->someone_died)
	{
		pthread_mutex_unlock(&philo->shared->kill_lock);
		return (1);
	}
	pthread_mutex_unlock(&philo->shared->kill_lock);
	return (0);
}

void	eating(t_philosopher *philo)
{
	print_status(philo, "is eating");
	ft_usleep(philo->eat_time);
	if (philo->id % 2 == 0)
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
	}
	else
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
	}
}

int	check_phn(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->shared->death_lock);
	if (philo->phn != -1 && philo->meals_eaten >= philo->phn)
	{
		pthread_mutex_unlock(&philo->shared->death_lock);
		return (1);
	}
	pthread_mutex_unlock(&philo->shared->death_lock);
	return (0);
}

void	*philosopher_routine(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	if (philo->id % 2 == 0)
		ft_usleep(philo->eat_time - 10);
	while (1)
	{
		if (check_d(philo))
			break ;
		if (!take_forks(philo))
			break ;
		pthread_mutex_lock(&philo->shared->death_lock);
		philo->last_meal_time = get_time_ms();
		philo->meals_eaten++;
		pthread_mutex_unlock(&philo->shared->death_lock);
		eating(philo);
		if (check_phn(philo))
			break ;
		if (!print_status(philo, "is sleeping"))
			break ;
		ft_usleep(philo->sleep_time);
		if (!print_status(philo, "is thinking"))
			break ;
	}
	return (NULL);
}
