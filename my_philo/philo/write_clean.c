/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_clean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yofouzi <yofouzi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 09:20:48 by yofouzi           #+#    #+#             */
/*   Updated: 2025/08/24 13:24:21 by yofouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	write_safe(t_table *table, char *str, int id)
{
	long	timest;

	if (get_bool(&table->table_mutex, &table->philos[id - 1].full))
		return ;
	pthread_mutex_lock(&table->write_lock);
	if (!simulation_finished(table))
	{
		timest = get_current_time() - table->start_simulation;
		printf("%ld %d %s\n", timest, id, str);
	}
	pthread_mutex_unlock(&table->write_lock);
}

static void	clean_forks(t_table *table)
{
	int	i;

	if (!table->forks)
		return ;
	i = 0;
	while (i < table->philo_nbr)
	{
		pthread_mutex_destroy(&table->forks[i].fork);
		i++;
	}
	free_ptr((void **)&table->forks);
	table->forks = NULL;
}

static void	clean_philos(t_table *table)
{
	int	i;

	if (!table->philos)
		return ;
	i = 0;
	while (i < table->philo_nbr)
	{
		pthread_mutex_destroy(&table->philos[i].philo_mutex);
		i++;
	}
	free_ptr((void **)&table->philos);
	table->philos = NULL;
}

static void	destroy_table_mutexes(t_table *table)
{
	pthread_mutex_destroy(&table->table_mutex);
	pthread_mutex_destroy(&table->write_lock);
}

void	clean_up(t_table *table)
{
	if (!table)
		return ;
	clean_forks(table);
	clean_philos(table);
	destroy_table_mutexes(table);
}
