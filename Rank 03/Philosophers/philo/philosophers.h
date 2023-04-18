/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramartin <ramartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 15:12:02 by rafael            #+#    #+#             */
/*   Updated: 2023/04/18 18:28:36 by ramartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

/* Simulation Struct */
typedef struct s_philo
{
	int	philo;
	int	death_time;
	int	eating_time;
	int	sleeping_time;
	int	times_to_eat;
}t_philo;

/* Forks Struct */
typedef struct s_mutex
{
	t_philo			p;
	pthread_mutex_t	*forks;
	int				philo_id;
	int				fork_n;
	pthread_mutex_t	may_start;
	int				start;
	int				next;
	struct timeval	start_time;
	struct timeval	current_time;
}t_mutex;

/* Philosopher Struct*/
/*0 == Eating*/
/*1 == Sleeping*/
/*2 == Thinking*/
typedef struct s_philo_data
{
	int				id;
	int				left_f;
	int				right_f;
	int				ended;
	int				times_eaten;
	int				current_state;
	struct timeval	since_meal;
	struct timeval	last_ate;
}t_philo_data;

/* Main functions */
void	philo_error_handling(int error_code);
void	philo_end(t_philo simu_data, pthread_t *philos, t_mutex *mutex);
void	philo_start(t_philo simu_data, pthread_t *philos, t_mutex *mutex);
void	philo_simulation(t_philo simu_data);
void	*philo_life_cycle(void *forks);

/* Utils */
void	philo_start_values(t_philo_data *data, t_mutex **m, void **forks_pointer);
int		philo_elapsed_time(struct timeval start_time);
int		ft_atoi(char *str);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/* Verification */
int		philo_check_int_limits(int len, char *input);
int		philo_check_if_int(char *input);
int		philo_check_input(int args, char **input);

#endif
