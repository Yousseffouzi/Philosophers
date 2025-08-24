/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yofouzi <yofouzi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 16:15:41 by yofouzi           #+#    #+#             */
/*   Updated: 2025/08/23 23:56:10 by yofouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	assign_forks(t_philo *philo, t_fork *fork, int position)
{
	int	philo_nbr;

	philo_nbr = philo->table->philo_nbr;
	philo->first_fork = &fork[(position + 1) % philo_nbr];
	philo->second_fork = &fork[position];
	if (philo->id)
	{
		philo->first_fork = &fork[position];
		philo->second_fork = &fork[(position + 1) % philo_nbr];
	}
}

static int	philo_init(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philo_nbr)
	{
		table->philos[i].id = i + 1;
		table->philos[i].full = false;
		table->philos[i].meals_counter = 0;
		table->philos[i].table = table;
		if (pthread_mutex_init(&table->philos[i].philo_mutex, NULL))
			return (1);
		assign_forks(&table->philos[i], table->forks, i);
		i++;
	}
	return (0);
}

t_table	*data_init_value(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philo_nbr)
	{
		if (pthread_mutex_init(&table->forks[i].fork, NULL))
		{
			destroy_all(table);
			return (NULL);
		}
		table->forks[i].fork_id = i;
		i++;
	}
	if (philo_init(table))
	{
		destroy_all(table);
		return (NULL);
	}
	return (table);
}

t_table	*data_init(t_table *table)
{
	t_table	*value;

	if (!table)
		return (NULL);
	table->end_simulation = false;
	table->all_threads_ready = false;
	table->threads_running_nbr = 0;
	if (pthread_mutex_init(&table->table_mutex, NULL)
		|| pthread_mutex_init(&table->write_lock, NULL))
		return (NULL);
	table->philos = malloc(sizeof(t_philo) * table->philo_nbr);
	table->forks = malloc(sizeof(t_fork) * table->philo_nbr);
	if (!table->philos || !table->forks)
	{
		cleanup_init_malloc(table);
		return (NULL);
	}
	value = data_init_value(table);
	if (!value)
		return (NULL);
	return (value);
}
