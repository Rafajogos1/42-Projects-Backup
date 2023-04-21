/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_utils_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 23:28:50 by rafael            #+#    #+#             */
/*   Updated: 2023/04/22 00:16:01 by rafael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_mutex_init(t_philo simu_data, t_mutex *mutex)
{
	int	i;

	i = 0;
	while (i < simu_data.philo)
	{
		pthread_mutex_init(&(mutex->forks[i]), NULL);
		pthread_mutex_unlock(&(mutex->forks[i]));
		i++;
	}
}

void	philo_death_checker(t_mutex *mutex)
{
	int	i;

	while (mutex->still_alive > 0)
	{
		i = 0;
		while (i < mutex->fork_n)
		{
			if (mutex->philo_data_arr[i]->current_state != 3)
			{
				if (check_if_dead(mutex->philo_data_arr[i]->last_ate, \
				mutex->philo_data_arr[i]->since_meal, mutex, i + 1))
				{
					mutex->philo_data_arr[i]->current_state = 3;
					mutex->still_alive--;
				}
			}
			i++;
		}
	}
}
