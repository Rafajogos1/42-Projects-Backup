/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_threads_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramartin <ramartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:04:36 by ramartin          #+#    #+#             */
/*   Updated: 2023/08/14 17:26:53 by ramartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_sleep(t_mutex *m, int *current_state)
{
	int			id;

	id = m->philo_id;
	printf("%i %i is sleeping\n", philo_elapsed_time(m->start_time), id);
	usleep(m->p.sleeping_time);
	*current_state = 0;
}
