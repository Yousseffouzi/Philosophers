/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanmazir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:48:21 by aanmazir          #+#    #+#             */
/*   Updated: 2025/04/17 13:48:59 by aanmazir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <limits.h>
# include <sys/time.h>

typedef struct s_philos
{
	int				philos;
	int				eat_time;
	int				sleep_time;
	int				die_time;
	int				meals_nb;
	long			start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	death_lock;
	pthread_mutex_t	kill_lock;
	int				someone_died;
}	t_philos;

typedef struct s_philosopher
{
	int				id;
	int				meals_eaten;
	int				phn; // number of meals to eat
	int				eat_time;
	int				sleep_time;
	int				die_time;
	long			last_meal_time;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_philos		*shared;
}	t_philosopher;

// Helper Functions
int			ft_atoi(const char *str);
int			ft_isdigit(char c);

// Program Funcs
int			args_verified(char **args);
void		philosophers_algo(t_philos *philo);
t_philos	*program_init(char **args);
void		*philosopher_routine(void *arg);
void		*death_monitor(void *arg);
t_philos	*program_init(char **args);
long		get_time_ms(void);
int			print_status(t_philosopher *philo, char *status);
int			take_forks(t_philosopher *philo);
int			ft_usleep(size_t milliseconds);

#endif
