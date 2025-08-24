/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yofouzi <yofouzi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 17:07:36 by yofouzi           #+#    #+#             */
/*   Updated: 2025/08/24 13:24:05 by yofouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

typedef struct s_table	t_table;

typedef struct s_fork
{
	pthread_mutex_t		fork;
	long				fork_id;
}						t_fork;

typedef struct s_philo
{
	long				id;
	bool				full;
	long				meals_counter;
	long				last_meal_time;
	pthread_mutex_t		philo_mutex;
	t_fork				*first_fork;
	t_fork				*second_fork;
	pthread_t			thread_id;
	t_table				*table;
}						t_philo;

struct					s_table
{
	long				philo_nbr;
	long				time_to_eat;
	long				time_to_die;
	long				time_to_sleep;
	long				nbr_limit_meals;
	long				start_simulation;
	bool				end_simulation;
	bool				all_threads_ready;
	long				threads_running_nbr;
	t_fork				*forks;
	t_philo				*philos;
	pthread_mutex_t		table_mutex;
	pthread_mutex_t		write_lock;
	pthread_t			monitor;
};

// parse_input
int						parse_input(t_table *table, char **args);

// data_init
t_table					*data_init(t_table *table);

// utils
void					free_ptr(void **ptr);
void					cleanup_init_malloc(t_table *table);
void					destroy_all(t_table *table);

// time
long					get_current_time(void);
long					get_current_time_microseconds(void);
void					my_usleep(long usec, t_table *table);

// get_set
bool					get_bool(pthread_mutex_t *mutex, bool *value);
void					set_bool(pthread_mutex_t *mutex, bool *dest,
							bool value);
long					get_long(pthread_mutex_t *mutex, long *value);
void					set_long(pthread_mutex_t *mutex, long *dest,
							long value);
long					simulation_finished(t_table *table);
// write_clean
void					write_safe(t_table *table, char *str, int id);
void					clean_up(t_table *table);

// synchronization

void					increment_long(pthread_mutex_t *mutex, long *value);
bool					all_threads_running(pthread_mutex_t *mutex,
							long *threads, long philo_nbr);
void					synchro_all_threads(t_table *table);
void					de_synchronize_philos(t_philo *philo);

// dinner
void					start_dinner(t_table *table);
void					*dinner_simulation(void *data);
void					eat(t_philo *philo);
void					thinking(t_philo *philo);

// monitor
void					*monitor_simulation(void *data);
