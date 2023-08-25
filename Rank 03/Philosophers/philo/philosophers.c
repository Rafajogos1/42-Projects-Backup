/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramartin <ramartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:53:29 by ramartin          #+#    #+#             */
/*   Updated: 2023/08/25 18:44:53 by ramartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	philo_error_handling(int error_code)
{
	if (error_code == -1)
		write(2, "Memory allocation error.\n", 26);
	if (error_code == 0)
		write(2, "Error: Wrong number of arguments.\n", 35);
	if (error_code == 1)
		write(2, "Error: At least one argument isn't a positive integer.\n", 56);
	if (error_code == 2)
		write(2, "Only the number of times to eat can be null.\n", 46);
	return (0);
}

void	philo_start(t_philo *p)
{
	int	i;

	i = 0;
	philo_mutex_init(p);
	while (i < p->philo_n)
	{
		pthread_create(&(p->p_threads[i]), NULL, philo_life_cycle, (void *)(p));
	}
}

int	philo_simulation(t_philo *philo)
{
	philo->p_threads = malloc(sizeof(pthread_t) * philo->philo_n);
	philo->forks = malloc(sizeof(pthread_mutex_t) * philo->philo_n);
	philo->philo_data_arr = malloc(sizeof(t_philo_data) * philo->philo_n);
	if (!(philo->p_threads) || !(philo->forks) || !(philo->philo_data_arr))
		return (philo_error_handling(-1));
	philo_start(philo);
}

int	main(int ac, char **av)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (philo == NULL)
		return (philo_error_handling(-1));
	if ((ac == 5) || (ac == 6))
	{
		if (philo_check_input(ac, av) == 1)
		{
			philo_store_values(philo, ac, av);
			philo_simulation(philo);
		}
		else if (philo_check_input(ac, av) == 0)
			return (philo_error_handling(1));
		else
			return (philo_error_handling(2));
	}
	else
		return (philo_error_handling(0));
	free(philo);
}
