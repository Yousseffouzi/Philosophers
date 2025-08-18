/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdahman <abdahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 22:49:57 by abdahman          #+#    #+#             */
/*   Updated: 2025/05/18 14:02:27 by abdahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	clean_all(t_data *data)
{
	sem_close(data->fork);
	sem_close(data->print);
	sem_close(data->deid);
	sem_close(data->eat);
	sem_close(data->access);
	sem_close(data->end_eating);
	sem_close(data->check);
	sem_unlink("/forks");
	sem_unlink("/print");
	sem_unlink("/died");
	sem_unlink("/eat");
	sem_unlink("/access");
	sem_unlink("/end_eating");
	sem_unlink("/check");
	if (data->philo)
		free(data->philo);
	if (data->pid)
		free(data->pid);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 5 && ac != 6)
		return (printf("invalid input !\n"));
	get_values(av, &data);
	if (init_philo(&data))
		return (1);
	if (init_semaphore(&data))
		return (free(data.philo), 1);
	start_process(&data);
	clean_all(&data);
	return (0);
}
