/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_threads.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramartin <ramartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:32:52 by rafael            #+#    #+#             */
/*   Updated: 2023/04/10 18:20:18 by ramartin         ###   ########.fr       */
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
