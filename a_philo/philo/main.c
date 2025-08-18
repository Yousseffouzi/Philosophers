/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdahman <abdahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 18:41:50 by abdahman          #+#    #+#             */
/*   Updated: 2025/05/18 11:05:09 by abdahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 5 && ac != 6)
		return (write(1, "invalid input !!\n", 17), 1);
	get_values(av, &data);
	if (init_mutexes(&data) != 0)
		return (1);
	if (init_philosophers(&data) != 0)
		return (1);
	start_threads(&data);
	return (0);
}
