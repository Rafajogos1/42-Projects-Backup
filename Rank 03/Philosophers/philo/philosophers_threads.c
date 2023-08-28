/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_threads.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramartin <ramartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 18:40:28 by ramartin          #+#    #+#             */
/*   Updated: 2023/08/28 17:43:36 by ramartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*philo_life_cycle(void *data)
{
	t_philo			*p;
	t_philo_data	d;

	philo_start_values(&data, &p, &d);

	p->next = 1;
	printf("AAAAA\n");
	while (p->created_philos != p->philo_n)
		if (p->created_philos == p->philo_n)
			p->start = 1;
	printf("I'm philosopher %i.\n", d.id);
	pthread_exit(NULL);
}
