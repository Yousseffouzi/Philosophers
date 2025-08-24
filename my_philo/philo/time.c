/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yofouzi <yofouzi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 09:03:48 by yofouzi           #+#    #+#             */
/*   Updated: 2025/08/24 10:12:40 by yofouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_current_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (1);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

long	get_current_time_microseconds(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (1);
	return ((tv.tv_sec * 1000000) + tv.tv_usec);
}

void	my_usleep(long usec, t_table *table)
{
	long	past;
	long	start;
	long	rem;

	start = get_current_time_microseconds();
	while (get_current_time_microseconds() - start < usec)
	{
		if (simulation_finished(table))
			break ;
		past = get_current_time_microseconds() - start;
		rem = usec - past;
		if (rem > 1000)
			usleep(rem / 2);
		else
		{
			while (get_current_time_microseconds() - start < usec)
				;
		}
	}
}
