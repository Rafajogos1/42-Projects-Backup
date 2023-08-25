/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramartin <ramartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:53:31 by ramartin          #+#    #+#             */
/*   Updated: 2023/08/25 17:38:39 by ramartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <errno.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

/* Philosopher Struct*/
/*0 == Thinking*/
/*1 == Eating*/
/*2 == Sleeping*/
/*3 == Dead */
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

/* Simulation Struct */
typedef struct s_philo
{
	int				philo;
	int				death_time;
	int				eating_time;
	int				sleeping_time;
	int				times_to_eat;
	t_philo_data	**philo_data_arr;
	pthread_t		*philos;
	pthread_mutex_t	*forks;
	struct timeval	start_time;
	struct timeval	current_time;
}t_philo;

/* Utils */
int		ft_atoi(char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);
void	philo_store_values(t_philo *simu_data, int ac, char **av);

/* Verify */
int		philo_check_int_limits(int len, char *input);
int		philo_check_if_int(char *input);
int		philo_check_input(int args, char **input);

#endif