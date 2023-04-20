/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_threads.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:32:52 by rafael            #+#    #+#             */
/*   Updated: 2023/04/20 21:28:36 by rafael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_pick_forks(t_philo_data *d, t_mutex *m)
{
	int			ts;
	static int	tries = 1;

	while ((*d).holding_both == 0)
	{
		if (check_if_dead((*d).last_ate, (*d).since_meal, m, (*d).id) == 1)
		{
			(*d).current_state = 3;
			return ;
		}
		if (pthread_mutex_lock(&(m->forks[(*d).left_f])) == 0)
		{
			if (pthread_mutex_lock(&(m->forks[(*d).right_f])) == 0)
			{
				printf("%i nice\n", (*d).id);
				(*d).holding_both = 1;
				pthread_mutex_unlock(&(m->forks[(*d).left_f]));
				pthread_mutex_unlock(&(m->forks[(*d).right_f]));
			}
			else
			{
				pthread_mutex_unlock(&(m->forks[(*d).left_f]));
				printf("%i too bad double :(\n", (*d).id);
				usleep(1000 * (2 * tries++));
				return ;
			}
		}
		else
		{
			printf("%i too bad :(\n", (*d).id);
			usleep(1000 * (2 * tries++));
			return ;
		}
	}
	ts = 0;
	printf("%i %p\n", ts, m);
	(*d).current_state = 1;
	tries = 0;
	return ;
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
	m->next = 1;
	while (m->philos != m->fork_n)
		if (m->philos == m->fork_n)
			m->start = 1;
	gettimeofday(&(data.last_ate), NULL);
	while (!data.ended && data.current_state != 3)
	{
		gettimeofday(&(data.since_meal), NULL);
		if (check_if_dead(data.last_ate, data.since_meal, m, data.id) == 1)
			data.current_state = 3;
		if (data.current_state == 0)
			philo_pick_forks(&data, m);
		if ((m->p.times_to_eat > 0) && (data.times_eaten == m->p.times_to_eat))
			data.ended = !data.ended;
	}
	pthread_exit(NULL);
}
