/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdahman <abdahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 12:22:01 by abdahman          #+#    #+#             */
/*   Updated: 2025/05/18 14:09:03 by abdahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	print_message(t_philo *philo, char *message)
{
	long long	current_time;

	sem_wait(philo->data->print);
	sem_wait(philo->data->deid);
	if (philo->data->is_died)
	{
		sem_post(philo->data->deid);
		sem_post(philo->data->print);
		return ;
	}
	sem_post(philo->data->deid);
	current_time = get_time() - philo->data->start_time;
	printf("%lld %d %s", current_time, philo->id + 1, message);
	sem_post(philo->data->print);
}
