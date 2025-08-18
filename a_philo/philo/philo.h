/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdahman <abdahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:54:41 by abdahman          #+#    #+#             */
/*   Updated: 2025/05/18 18:11:34 by abdahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>

typedef struct s_philo
{
	int				id;
	int				eating_time;
	long long		last_eating_time;
	int				left_fork;
	int				right_fork;
	pthread_t		thread;
	struct s_data	*data;
	pthread_mutex_t	eating_mutex;
}	t_philo;

typedef struct s_data
{
	int				num_philo;
	int				time_to_die;
	int				eat_time;
	int				sleep_time;
	int				num_time_to_eat;
	long long		start_time;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	death_mutex;
	int				someone_died;
	int				end_eating;
}	t_data;

void		cleanup(t_data *data);
int			init_philosophers(t_data *data);
void		*philosopher_routine(void *arg);
int			init_mutexes(t_data *data);
void		*monitor_routine(void *arg);
int			ft_atoi(char *str);
void		get_values(char **av, t_data *data);
void		ft_putnbr(int n);
void		ft_putchar(char c);
void		print_message(t_philo *philo, char *message);
long long	get_time(void);
int			eat(t_philo *philo);
void		take_forks(t_philo *philo);
int			start_threads(t_data *data);

#endif
