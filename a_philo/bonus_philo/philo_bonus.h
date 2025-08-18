/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdahman <abdahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 22:50:31 by abdahman          #+#    #+#             */
/*   Updated: 2025/05/18 14:17:52 by abdahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <fcntl.h>
# include <sys/time.h>
# include <string.h>
# include <semaphore.h>
# include <sys/wait.h>
# include </usr/include/x86_64-linux-gnu/bits/signum-generic.h>

typedef struct s_philo
{
	int				id;
	pid_t			pid;
	long long		last_time_to_eat;
	int				time_to_eat;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	int				num_philo;
	int				time_to_die;
	int				eat_time;
	int				sleep_time;
	int				num_time_to_eat;
	int				is_died;
	pid_t			*pid;
	long long		start_time;
	t_philo			*philo;
	sem_t			*fork;
	sem_t			*eat;
	sem_t			*print;
	sem_t			*deid;
	sem_t			*access;
	sem_t			*end_eating;
	sem_t			*check;
	sem_t			*done;
}	t_data;

int			ft_atoi(char *str);
void		get_values(char **av, t_data *data);
long long	get_time(void);
void		print_message(t_philo *philo, char *message);
void		eat(t_philo *philo);
int			init_philo(t_data *data);
int			init_semaphore(t_data *data);
void		kill_all_process(t_data *data);
int			is_died(t_philo *philo);
void		*monitor_eat_routine(void *arg);
int			start_process(t_data *data);
void		philo_rotine(t_philo philo);
void		*monitor_routine(void *arg);
void		clean_all(t_data *data);
void		philo_rotine(t_philo philo);
void		philo_help(t_philo *philo);
void		*monitor_routine(void *arg);

#endif
