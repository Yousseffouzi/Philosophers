/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yofouzi <yofouzi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 19:00:57 by yofouzi           #+#    #+#             */
/*   Updated: 2025/08/23 19:25:37 by yofouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_ptr(void **ptr)
{
	if (ptr || *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

void	cleanup_init_malloc(t_table *table)
{
	free_ptr((void **)&table->philos);
	free_ptr((void **)&table->forks);
	pthread_mutex_destroy(&table->table_mutex);
	pthread_mutex_destroy(&table->write_lock);
}

void	destroy_all(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philo_nbr)
	{
		pthread_mutex_destroy(&table->forks[i].fork);
		pthread_mutex_destroy(&table->philos[i].philo_mutex);
		i++;
	}
	cleanup_init_malloc(table);
}
