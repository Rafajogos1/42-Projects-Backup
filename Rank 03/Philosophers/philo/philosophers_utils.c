/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 15:16:37 by rafael            #+#    #+#             */
/*   Updated: 2023/04/18 21:43:53 by rafael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_start_values(t_philo_data *data, t_mutex **m, void **fp)
{
	*m = (t_mutex *) *fp;
	data->id = (*m)->philo_id;
	if (data->id == 1)
	{
		data->left_f = ((*m)->fork_n - 1);
		data->right_f = (data->id - 1);
	}
	else
	{
		data->left_f = (data->id - 2);
		data->right_f = (data->id - 1);
	}
	data->holding_both = 0;
	data->ended = 0;
	data->times_eaten = 0;
	data->current_state = 0;
}

int	philo_elapsed_time(struct timeval start_time)
{
	struct timeval	time;
	int				elapsed_time;

	gettimeofday(&time, NULL);
	elapsed_time = (((time.tv_sec - start_time.tv_sec) * 1000 \
	+ (time.tv_usec - start_time.tv_usec) / 1000));
	return (elapsed_time);
}

int	ft_atoi(char *str)
{
	int	num;
	int	neg;
	int	found;

	num = 0;
	neg = 1;
	found = 1;
	while ((*str == ' ') || (*str == '\t') || (*str == '\n') \
	|| (*str == '\r') || (*str == '\f'))
		str++;
	if ((*str == '+') || (*str == '-'))
	{
		if (*str == '-')
			neg = -1;
		str++;
	}
	while (*str && found)
	{
		if ((*str >= '0') && (*str <= '9'))
			num = (num * 10 + *str -48);
		else
			found = 0;
		str++;
	}
	return (num * neg);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] != '\0' && s1[i] == s2[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}
