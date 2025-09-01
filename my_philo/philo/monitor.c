/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yofouzi <yofouzi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 11:59:47 by yofouzi           #+#    #+#             */
/*   Updated: 2025/08/24 13:11:52 by yofouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static long	philo_died(t_philo *philo)
{
	long	past;
	long	die;

	if (get_bool(&philo->philo_mutex, &philo->full))
		return (0);
	past = get_current_time() - get_long(&philo->philo_mutex,
			&philo->last_meal_time);
	die = philo->table->time_to_die / 1000;
	if (past > die)
		return (1);
	else
		return (0);
}

static int	all_philo_full(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philo_nbr)
	{
		if (!get_bool(&table->table_mutex, &table->philos[i].full))
			return (0);
		i++;
	}
	return (1);
}

void	*monitor_simulation(void *data)
{
	t_table	*table;
	int		i;

	table = (t_table *)data;
	while (!all_threads_running(&table->table_mutex,
			&table->threads_running_nbr, table->philo_nbr))
		;
	while (!simulation_finished(table))
	{
		i = -1;
		while (++i < table->philo_nbr && !simulation_finished(table))
		{
			if (philo_died(table->philos + i))
			{
				write_safe(table, "died", table->philos[i].id);
				set_bool(&table->table_mutex, &table->end_simulation, true);
			}
		}
		if (table->nbr_limit_meals > 0 && all_philo_full(table))
			set_bool(&table->table_mutex, &table->end_simulation, true);
		usleep(5000);
	}
	return (NULL);
}
