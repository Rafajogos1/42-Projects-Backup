/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramartin <ramartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:53:29 by ramartin          #+#    #+#             */
/*   Updated: 2023/08/25 17:36:42 by ramartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	philo_error_handling(int error_code)
{
	if (error_code == -1)
		write(2, "Memory allocation error.\n", 26);
	if (error_code == 0)
		write(2, "Error: Wrong number of arguments.\n", 35);
	if (error_code == 1)
		write(2, "Error: At least one argument isn't a positive integer.\n", 56);
	if (error_code == 2)
		write(2, "Times and number of philosophers must not be null.\n", 52);
	return (0);
}

void	philo_simulation(t_philo *philo)
{
	
}

int	main(int ac, char **av)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (philo == NULL)
		return (philo_error_handling(-1));
	if ((ac == 5) || (ac == 6))
	{
		if (philo_check_input(ac, av) == 1)
		{
			philo_store_values(philo, ac, av);
			philo_simulation(philo);
		}
		else if (philo_check_input(ac, av) == 0)
			philo_error_handling(1);
		else
			philo_error_handling(2);
	}
	else
		philo_error_handling(0);
	free(philo);
}
