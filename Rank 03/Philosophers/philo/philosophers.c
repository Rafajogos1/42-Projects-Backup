/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 15:16:35 by rafael            #+#    #+#             */
/*   Updated: 2023/04/08 22:39:49 by rafael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_error_handling(int error_code)
{
	if (error_code == -1)
		write(2, "Memory allocation error.\n", 26);
	if (error_code == 0)
		write(2, "Error: Wrong number of arguments.\n", 35);
	if (error_code == 1)
		write(2, "Error: At least one argument isn't a positive integer.\n", 56);
	if (error_code == 2)
		write(2, "Times and number of philosophers must not be null.\n", 52);
}

void	philo_end(t_philo simu_data, pthread_t *philos, t_mutex *mutex)
{
	int	i;

	i = 0;
	while (i < simu_data.philo)
	{
		pthread_join(philos[i], NULL);
		i++;
	}
	printf("%p\n", mutex);
}

void	philo_start(t_philo simu_data, pthread_t *philos, t_mutex *mutex)
{
	int				i;

	i = 0;
	while (i < simu_data.philo)
	{
		mutex->philo_id = (i + 1);
		pthread_mutex_init(&(mutex->forks[i]), NULL);
		printf("%i\n", mutex->philo_id);
		pthread_create(&philos[i], NULL, philo_life_cycle, (void *)(mutex));
		usleep(100);
		i++;
	}
}

void	philo_simulation(t_philo simu_data)
{
	pthread_t	*philos;
	t_mutex		*mutex;

	philos = malloc(sizeof(pthread_t) * simu_data.philo);
	mutex = malloc(sizeof(t_mutex));
	mutex->forks = malloc(sizeof(pthread_mutex_t) * simu_data.philo);
	if (!philos || !mutex || !mutex->forks)
	{
		philo_error_handling(-1);
		return ;
	}
	philo_start(simu_data, philos, mutex);
	philo_end(simu_data, philos, mutex);
}

int	main(int ac, char **av)
{
	t_philo	simu_data;

	if ((ac == 5) || (ac == 6))
	{
		if (philo_check_input(ac, av) == 1)
		{
			simu_data.philo = ft_atoi(av[1]);
			simu_data.death_time = ft_atoi(av[2]);
			simu_data.eating_time = ft_atoi(av[3]);
			simu_data.sleeping_time = ft_atoi(av[4]);
			if (ac == 5)
				simu_data.times_to_eat = 0;
			else
				simu_data.times_to_eat = ft_atoi(av[5]);
			philo_simulation(simu_data);
		}
		else if (philo_check_input(ac, av) == 0)
			philo_error_handling(1);
		else
			philo_error_handling(2);
	}
	else
		philo_error_handling(0);
}
