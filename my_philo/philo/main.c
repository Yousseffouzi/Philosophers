/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yofouzi <yofouzi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 17:04:06 by yofouzi           #+#    #+#             */
/*   Updated: 2025/08/24 13:24:35 by yofouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_table	table;
	int		parse;

	if (ac == 5 || ac == 6)
	{
		parse = parse_input(&table, av);
		if (parse == -1)
			return (printf("wrong input : try -> ./philo 4 410 200 200\n"));
		if (parse == -2)
			return (printf("System can't handle timestamps < 60ms\n"));
		if (!data_init(&table))
			return (printf("Failed to initialize data\n"));
		start_dinner(&table);
		clean_up(&table);
	}
	else
		printf("wrong input : try -> ./philo 4 410 200 200\n");
	return (0);
}
