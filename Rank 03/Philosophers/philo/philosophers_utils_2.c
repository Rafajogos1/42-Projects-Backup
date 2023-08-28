/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_utils_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramartin <ramartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 17:14:33 by ramartin          #+#    #+#             */
/*   Updated: 2023/08/28 17:40:12 by ramartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_start_values(void **d, t_philo **data, t_philo_data *p_data)
{
	*data = (t_philo *) *d;
	p_data->id = (*data)->current_philo;
	p_data->right_f = (p_data->id - 1);
	if (p_data->id == 1)
		p_data->left_f = ((*data)->philo_n - 1);
	else
		p_data->left_f = (p_data->id - 2);
	p_data->ended = 0;
	p_data->times_eaten = 0;
	p_data->current_state = 0;
	(*data)->philo_data_arr[p_data->id - 1] = p_data;
	(*data)->alive_philos = (*data)->philo_n;
}
