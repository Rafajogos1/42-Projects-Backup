/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_threads.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramartin <ramartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:32:52 by rafael            #+#    #+#             */
/*   Updated: 2023/04/14 17:45:53 by ramartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_death(int id, int timestamp)
{
	printf("%i %i died\n", timestamp, id);
}

int	check_if_dead(struct timeval l_a, struct timeval s_m, t_mutex *m, int id)
{
	if (((s_m.tv_sec - l_a.tv_sec) * 1000 + \
	(s_m.tv_usec - l_a.tv_usec) / 1000) >= m->p.death_time)
	{
		gettimeofday(&(m->current_time), NULL);
		philo_death(id, ((m->current_time.tv_sec - m->start_time.tv_sec) \
		* 1000 + (m->current_time.tv_usec - m->start_time.tv_usec) / 1000));
		return (1);
	}
	else
		return (0);
}

void	*philo_life_cycle(void *forks_pointer)
{
	t_mutex			*m;
	t_philo_data	data;

	data.ended = 0;
	data.times_eaten = 0;
	m = (t_mutex *) forks_pointer;
	data.id = m->philo_id;
	gettimeofday(&(data.last_ate), NULL);
	printf("I'm philosopher %i.\n", data.id);
	while (!data.ended)
	{
		gettimeofday(&(data.since_meal), NULL);
		if (check_if_dead(data.last_ate, data.since_meal, m, data.id) == 1)
			data.ended = !data.ended;
		if ((m->p.times_to_eat > 0) && (data.times_eaten == m->p.times_to_eat))
			data.ended = !data.ended;
	}
	printf("End %i.\n", data.id);
	pthread_exit(NULL);
}
