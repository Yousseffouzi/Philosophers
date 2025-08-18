/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdahman <abdahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 19:52:16 by abdahman          #+#    #+#             */
/*   Updated: 2025/05/18 14:08:30 by abdahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*monitor_died(void *arg)
{
	t_data	*data;
	int		i;

	i = 0;
	data = (t_data *)arg;
	sem_wait(data->check);
	while (data->num_philo > 0 && i < data->num_philo)
	{
		sem_post(data->end_eating);
		i++;
	}
	kill_all_process(data);
	return (NULL);
}

void	*monitor_eat(void *arg)
{
	t_data	*data;
	int		i;

	i = 0;
	data = (t_data *)arg;
	if (data->num_time_to_eat > 0)
	{
		while (i < data->num_philo)
		{
			sem_wait(data->end_eating);
			i++;
		}
		sem_post(data->check);
	}
	return (NULL);
}

void	ft_waitpid(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philo)
	{
		waitpid(data->pid[i], NULL, 0);
		i++;
	}
	return ;
}

int	start_process(t_data *data)
{
	int			i;
	pthread_t	check_died;
	pthread_t	check_eat;

	i = -1;
	data->start_time = get_time();
	while (++i < data->num_philo)
	{
		data->pid[i] = fork();
		if (data->pid[i] < 0)
			return (kill_all_process(data), perror("fork filed !\n"), 1);
		else if (data->pid[i] == 0)
		{
			data->philo[i].last_time_to_eat = get_time();
			philo_rotine(data->philo[i]);
			return (0);
		}
	}
	if (pthread_create(&check_died, NULL, monitor_died, data) != 0
		|| pthread_create(&check_eat, NULL, monitor_eat, data) != 0)
		return (kill_all_process(data), perror("pthread filed !\n"), 1);
	pthread_detach(check_eat);
	pthread_detach(check_died);
	ft_waitpid(data);
	return (0);
}
