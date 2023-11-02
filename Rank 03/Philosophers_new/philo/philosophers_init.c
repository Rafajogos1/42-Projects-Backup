/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 21:19:48 by rafael            #+#    #+#             */
/*   Updated: 2023/10/27 21:33:49 by rafael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* This function initiates the mutexes. */
/* @param data The data structure. */
void	philo_init_forks(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philo_num)
		pthread_mutex_init(&data->forks[i], NULL);
	i = 0;
	data->philos[0].l_fork = &data->forks[0];
	data->philos[0].r_fork = &data->forks[data->philo_num - 1];
	i = 1;
	while (i < data->philo_num)
	{
		data->philos[i].l_fork = &data->forks[i];
		data->philos[i].r_fork = &data->forks[i - 1];
		i++;
	}
}

/* This function stores the necessary values into each philosopher. */
/* @param data The data structure. */
void	philo_init_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_num)
	{
		data->philos[i].data = data;
		data->philos[i].id = i + 1;
		data->philos[i].time_to_die = data->death_time;
		data->philos[i].eat_count = 0;
		data->philos[i].eating = 0;
		data->philos[i].status = 0;
		pthread_mutex_init(&data->philos[i].lock, NULL);
		i++;
	}
}

/* This function stores the data into the data structure. */
/* @param data The data structure.*/
/* @param av The argument vector. */
/* @param ac The argument count. */
/* @return 1 if successful, 0 if not. */
int	philo_init_data(t_data *data, char **av, int ac)
{
	data->philo_num = ft_atoi(av[1]);
	data->death_time = ft_atoi(av[2]);
	data->eat_time = ft_atoi(av[3]);
	data->sleep_time = ft_atoi(av[4]);
	if (ac == 6)
		data->meals_nb = (int) ft_atoi(av[5]);
	else
		data->meals_nb = -1;
	if (data->philo_num > 200 || data->philo_num < 2)
		return (philo_error_handling(2));
	if (data->death_time <= 0 || data->eat_time <= 0 || data->sleep_time <= 0)
	{
		philo_exit(data);
		return (philo_error_handling(3));
	}
	data->dead = 0;
	data->finished = 0;
	pthread_mutex_init(&data->write, NULL);
	pthread_mutex_init(&data->lock, NULL);
	return (1);
}

/* This function initializes the values for the simulation to work with. */
/* @param data The structure containing data about the simulation. */
/* @param av The argument vector. */
/* @param ac The argument count. */
/* @return 1 if successful, 0 if not. */
int	philo_init(t_data *data, char **av, int ac)
{
	if (philo_init_data(data, av, ac) == 0)
		return (0);
	data->threads = malloc(sizeof(pthread_t) * data->philo_num);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_num);
	data->philos = malloc(sizeof(t_philo) * data->philo_num);
	if (!(data->threads) || !(data->forks) || !(data->philos))
	{
		philo_exit(data);
		return (philo_error_handling(-1));
	}
	philo_init_forks(data);
	philo_init_philos(data);
	return (1);
}
