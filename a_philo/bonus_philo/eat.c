/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdahman <abdahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:03:44 by abdahman          #+#    #+#             */
/*   Updated: 2025/05/18 11:41:34 by abdahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	eat(t_philo *philo)
{
	sem_wait(philo->data->eat);
	philo->time_to_eat++;
	philo->last_time_to_eat = get_time();
	sem_post(philo->data->eat);
	print_message(philo, "\033[0;32mis eating\033[0m\n");
	usleep(philo->data->eat_time * 1000 - 500);
	sem_post(philo->data->fork);
	sem_post(philo->data->fork);
	sem_post(philo->data->access);
	if (philo->data->num_time_to_eat > 0)
	{
		if (philo->time_to_eat >= philo->data->num_time_to_eat)
		{
			sem_post(philo->data->end_eating);
			sleep(1000);
		}
	}
}
