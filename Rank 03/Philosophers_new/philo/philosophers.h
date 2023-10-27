/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 21:19:27 by rafael            #+#    #+#             */
/*   Updated: 2023/10/27 21:21:31 by rafael           ###   ########.fr       */
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

typedef struct s_philo
{
	struct s_data	*data;
	pthread_t		t;
	int				id;
	int				eat_count;
	int				status;
	int				eating;
	int				time_to_die;
	pthread_mutex_t	lock;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
}	t_philo;

typedef struct s_data
{
	pthread_t		*threads;
	int				philo_num;
	int				meals_nb;
	int				dead;
	int				finished;
	t_philo			*philos;
	int				death_time;
	int				eat_time;
	int				sleep_time;
	int				start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	lock;
	pthread_mutex_t	write;
}	t_data;

/* Main functions */
int		philo_error_handling(int error_code);
int		philo_input_checker(char **av);

/* Initiation */
void	philo_init_forks(t_data *data);
void	philo_init_philos(t_data *data);
int		philo_init_data(t_data *data, char **av, int ac);
int		philo_init(t_data *data, char **av, int ac);

/* Utilities */
int		ft_atoi(const char *str);

#endif