/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdahman <abdahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 23:22:55 by abdahman          #+#    #+#             */
/*   Updated: 2025/05/16 20:32:30 by abdahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	long	l;

	l = n;
	if (l < 0)
	{
		ft_putchar('-');
		l = -l;
	}
	if (l > 9)
		ft_putnbr((l / 10));
	ft_putchar(((l % 10) + 48));
}

int	ft_atoi(char *str)
{
	long	res;
	int		i;

	i = 0;
	res = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			exit((write(1, "invalid number !!\n", 18), 1));
	if (str[i] < '0' || str[i] > '9')
		exit((write(1, "invalid number !!\n", 18), 1));
	while (str[i] >= '0' && str[i] <= '9')
		res = (res * 10) + (str[i++] - '0');
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] != '\0' || i == 0)
		exit((write(1, "invalid number !!\n", 18), 1));
	if (res > 2147483647)
		exit((write(1, "number too large !!\n", 20), 1));
	if (res == 0)
		exit((write(1, "number cannot be zero !!\n", 25), 1));
	return (res);
}

void	get_values(char **av, t_data *data)
{
	int	i;

	i = 0;
	data->num_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->eat_time = ft_atoi(av[3]);
	data->sleep_time = ft_atoi(av[4]);
	data->num_time_to_eat = -1;
	if (av[5])
		data->num_time_to_eat = ft_atoi(av[5]);
	data->is_died = 0;
	data->pid = malloc(sizeof(pid_t) * data->num_philo + 1);
	while (i < data->num_philo)
	{
		data->pid[i] = 0;
		i++;
	}
}
