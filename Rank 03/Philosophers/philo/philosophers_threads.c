/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_threads.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:32:52 by rafael            #+#    #+#             */
/*   Updated: 2023/04/08 22:38:12 by rafael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*philo_life_cycle(void *forks_pointer)
{
	t_mutex	*mutex;
	int		id;

	mutex = (t_mutex *) forks_pointer;
	id = mutex->philo_id;
	printf("I'm philosopher %i.\n", id);
	pthread_exit(NULL);
}
