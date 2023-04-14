/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_threads.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramartin <ramartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:32:52 by rafael            #+#    #+#             */
/*   Updated: 2023/04/14 11:16:26 by ramartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_death(int id, t_mutex *mutex)
{
	printf("%i %i died\n", id);
}

void	*philo_life_cycle(void *forks_pointer)
{
	t_mutex	*mutex;
	int		id;
	int		ended;
	int		last_ate;

	ended = 0;
	mutex = (t_mutex *) forks_pointer;
	id = mutex->philo_id;
	printf("I'm philosopher %i.\n", id);
	while(!ended)
	{
		ended = !ended;
	}
	printf("End %i.\n", id);
	pthread_exit(NULL);
}
