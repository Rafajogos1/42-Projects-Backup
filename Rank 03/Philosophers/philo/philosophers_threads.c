/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_threads.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramartin <ramartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:32:52 by rafael            #+#    #+#             */
/*   Updated: 2023/04/18 18:58:12 by ramartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_eat(t_philo_data d, t_mutex *m)
{
	int	ts;

	while (pthread_mutex_trylock(&(m->forks[d.left_f])) != 0 \
	|| pthread_mutex_trylock(&(m->forks[d.right_f])) != 0)
	{
		if (pthread_mutex_trylock(&(m->forks[d.left_f])) == 0)
		{
			gettimeofday(&(m->current_time), NULL);
			ts = ((m->current_time.tv_sec - m->start_time.tv_sec) \
		* 1000 + (m->current_time.tv_usec - m->start_time.tv_usec) / 1000);			
			printf("%i %i has taken a fork %i\n", ts, d.id, d.left_f);
			pthread_mutex_unlock(&(m->forks[d.left_f]));
		}
		if (pthread_mutex_trylock(&(m->forks[d.right_f])) == 0)
		{
			gettimeofday(&(m->current_time), NULL);
			printf("%i %i has taken a fork %i\n", ts, d.id, d.right_f);
			pthread_mutex_unlock(&(m->forks[d.right_f]));
		}
	}
	printf("%i %i has taken a fork\n", ts, d.id);
	printf("%i %i has taken a fork\n", ts, d.id);
}

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

	philo_start_values(&data, &m, &forks_pointer);
	while(m->start == 0)
		if (pthread_mutex_trylock(&(m->may_start)) == 0)
			m->start = 1;
	gettimeofday(&(data.last_ate), NULL);
	while (!data.ended)
	{
		gettimeofday(&(data.since_meal), NULL);
		if (check_if_dead(data.last_ate, data.since_meal, m, data.id) == 1)
			data.ended = !data.ended;
		if (data.current_state == 0)
			philo_eat(data, m);
		if ((m->p.times_to_eat > 0) && (data.times_eaten == m->p.times_to_eat))
			data.ended = !data.ended;
	}
	pthread_exit(NULL);
}
