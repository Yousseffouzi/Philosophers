/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdahman <abdahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 19:38:37 by abdahman          #+#    #+#             */
/*   Updated: 2025/05/18 14:09:40 by abdahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	kill_all_process(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philo)
	{
		if (data->pid[i] > 0)
			kill(data->pid[i], SIGKILL);
		i++;
	}
}
