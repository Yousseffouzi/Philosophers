/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yofouzi <yofouzi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 23:58:00 by yofouzi           #+#    #+#             */
/*   Updated: 2025/08/24 13:38:53 by yofouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thinking(t_philo *philo)
{
	long	eat;
	long	sleep;
	long	thing;

	if (philo->table->philo_nbr % 2 == 0)
		return ;
	eat = philo->table->time_to_eat;
	sleep = philo->table->time_to_sleep;
	thing = eat * 2 - sleep;
	if (thing < 0)
		thing = 0;
	my_usleep(thing * 0.4, philo->table);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->first_fork->fork);
	write_safe(philo->table, "has taken a fork", philo->id);
	pthread_mutex_lock(&philo->second_fork->fork);
	write_safe(philo->table, "has taken a fork", philo->id);
	set_long(&philo->philo_mutex, &philo->last_meal_time, get_current_time());
	philo->meals_counter++;
	write_safe(philo->table, "is eating", philo->id);
	my_usleep(philo->table->time_to_eat, philo->table);
	if (philo->table->nbr_limit_meals > 0
		&& philo->meals_counter == philo->table->nbr_limit_meals)
		set_bool(&philo->philo_mutex, &philo->full, true);
	pthread_mutex_unlock(&philo->first_fork->fork);
	pthread_mutex_unlock(&philo->second_fork->fork);
}

void	*dinner_simulation(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	synchro_all_threads(philo->table);
	set_long(&philo->philo_mutex, &philo->last_meal_time, get_current_time());
	increment_long(&philo->philo_mutex, &philo->table->threads_running_nbr);
	de_synchronize_philos(philo);
	while (!simulation_finished(philo->table))
	{
		if (get_bool(&philo->philo_mutex, &philo->full))
			break ;
		eat(philo);
		write_safe(philo->table, "is sleeping", philo->id);
		my_usleep(philo->table->time_to_sleep, philo->table);
		thinking(philo);
	}
	return (NULL);
}

static void	*single_philo(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	write_safe(philo->table, "has taken a fork", philo->id);
	my_usleep(philo->table->time_to_die, philo->table);
	write_safe(philo->table, "died", philo->id);
	return (NULL);
}

void	start_dinner(t_table *table)
{
	int	i;

	i = -1;
	if (table->nbr_limit_meals == 0)
		return ;
	else if (table->philo_nbr == 1)
	{
		table->start_simulation = get_current_time();
		pthread_create(&table->philos[0].thread_id, NULL, single_philo,
			&table->philos[0]);
		pthread_join(table->philos[0].thread_id, NULL);
		return ;
	}
	while (++i < table->philo_nbr)
		pthread_create(&table->philos[i].thread_id, NULL, dinner_simulation,
			&table->philos[i]);
	pthread_create(&table->monitor, NULL, monitor_simulation, table);
	table->start_simulation = get_current_time();
	set_bool(&table->table_mutex, &table->all_threads_ready, true);
	i = -1;
	while (++i < table->philo_nbr)
		pthread_join(table->philos[i].thread_id, NULL);
	set_bool(&table->table_mutex, &table->end_simulation, true);
	pthread_join(table->monitor, NULL);
}
