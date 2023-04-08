/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 15:12:02 by rafael            #+#    #+#             */
/*   Updated: 2023/04/08 22:38:19 by rafael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
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
	pthread_mutex_t	*forks;
	int				philo_id;
}t_mutex;

/* Main functions */
void	philo_error_handling(int error_code);
void	philo_simulation(t_philo simu_data);
void	*philo_life_cycle(void *forks);

/* Utils */
int		ft_atoi(char *str);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/* Verification */
int		philo_check_int_limits(int len, char *input);
int		philo_check_if_int(char *input);
int		philo_check_input(int args, char **input);

#endif
