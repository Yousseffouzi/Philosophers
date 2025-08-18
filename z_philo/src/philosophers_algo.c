/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_algo.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanmazir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 19:59:51 by aanmazir          #+#    #+#             */
/*   Updated: 2025/04/13 19:59:52 by aanmazir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	init_philos(int num_philosophers, t_philosopher *philosophers,
		t_philos *philo)
{
	int	i;

	i = 0;
	while (i < num_philosophers)
	{
		philosophers[i].id = i;
		philosophers[i].meals_eaten = 0;
		philosophers[i].phn = philo->meals_nb;
		philosophers[i].eat_time = philo->eat_time;
		philosophers[i].sleep_time = philo->sleep_time;
		philosophers[i].die_time = philo->die_time;
		philosophers[i].last_meal_time = get_time_ms();
		philosophers[i].shared = philo;
		philosophers[i].left_fork = &philo->forks[i];
		philosophers[i].right_fork = &philo->forks[(i + 1) % num_philosophers];
		if (num_philosophers % 2 == 0)
		{
			philosophers[i].left_fork = &philo->forks[(i + 1)
				% num_philosophers];
			philosophers[i].right_fork = &philo->forks[i];
		}
		pthread_create(&philosophers[i].thread, NULL, philosopher_routine,
			&philosophers[i]);
		i++;
	}
}

void	dstr_mtx(t_philos *philo, int num_philosophers)
{
	if (num_philosophers == 1)
	{
		pthread_mutex_destroy(&philo->forks[0]);
		pthread_mutex_destroy(&philo->write_lock);
		pthread_mutex_destroy(&philo->death_lock);
		pthread_mutex_destroy(&philo->kill_lock);
	}
	else
	{
		pthread_mutex_destroy(&philo->write_lock);
		pthread_mutex_destroy(&philo->death_lock);
		pthread_mutex_destroy(&philo->kill_lock);
	}
}

void	init_mutexes(t_philos *philo, int num_philosophers)
{
	int	i;

	i = 0;
	while (i < num_philosophers)
	{
		pthread_mutex_init(&philo->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&philo->write_lock, NULL);
	pthread_mutex_init(&philo->death_lock, NULL);
	pthread_mutex_init(&philo->kill_lock, NULL);
}

void	clean_all(int num_philosophers, t_philos *philo,
		t_philosopher *philosophers, pthread_t death_thread)
{
	int	i;

	i = 0;
	while (i < num_philosophers)
	{
		pthread_join(philosophers[i].thread, NULL);
		i++;
	}
	pthread_join(death_thread, NULL);
	i = 0;
	while (i < num_philosophers)
	{
		pthread_mutex_destroy(&philo->forks[i]);
		i++;
	}
	dstr_mtx(philo, num_philosophers);
	free(philosophers);
}

void	philosophers_algo(t_philos *philo)
{
	int				num_philosophers;
	t_philosopher	*philosophers;
	pthread_t		death_thread;

	num_philosophers = philo->philos;
	init_mutexes(philo, num_philosophers);
	philo->someone_died = 0;
	philo->start_time = get_time_ms();
	if (num_philosophers == 1)
	{
		printf("0 1 has taken a fork\n");
		ft_usleep(philo->die_time);
		printf("%d 1 died\n", philo->die_time);
		dstr_mtx(philo, num_philosophers);
		return ;
	}
	philosophers = malloc(sizeof(t_philosopher) * num_philosophers);
	if (!philosophers)
	{
		printf("Error: Memory allocation failed.\n");
		return ;
	}
	init_philos(num_philosophers, philosophers, philo);
	pthread_create(&death_thread, NULL, death_monitor, philosophers);
	clean_all(num_philosophers, philo, philosophers, death_thread);
}
