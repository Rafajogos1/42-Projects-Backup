/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 21:19:14 by rafael            #+#    #+#             */
/*   Updated: 2023/10/27 21:34:54 by rafael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* This function handles errors by printing a message*/
/* according to the error that occurred. */
/* @param error_code The error code to be provided. */
/* @return This function always returns 0 to prevent the program from running. */
int	philo_error_handling(int error_code)
{
	if (error_code == -1)
		write(2, "Memory allocation error.\n", 26);
	if (error_code == 0)
		write(2, "Error: Wrong number of arguments.\n", 35);
	if (error_code == 1)
		write(2, "Error: At least one argument isn't a positive integer.\n", 56);
	if (error_code == 2)
		write(2, "Simulation runs with 1 up to 200 philosophers.\n", 48);
	if (error_code == 3)
		write(2, "Only the number of times to eat can be null.\n", 46);
	return (0);
}

/* This function frees the memory used by the data structure. */
void	philo_clear_data(t_data	*data)
{
	if (data->threads)
		free(data->threads);
	if (data->forks)
		free(data->forks);
	if (data->philos)
		free(data->philos);
}

/* This function handles the exiting of the program by */
/* destroying the mutexes and by freeing the memory used with */
/* the `philo_exit` function. */
/* @param data The data structure. */
void	philo_exit(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philo_num)
	{
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&data->philos[i].lock);
	}
	pthread_mutex_destroy(&data->write);
	pthread_mutex_destroy(&data->lock);
	philo_clear_data(data);
}

/* The main function. */
int	main(int ac, char **av)
{
	t_data	data;

	if (ac < 5 || ac > 6)
		return (philo_error_handling(0));
	if (philo_input_checker(av) == 0)
		return (0);
	if (philo_init(&data, av, ac) == 0)
		return (0);
	printf("Fine\n");
	philo_exit(&data);
}
