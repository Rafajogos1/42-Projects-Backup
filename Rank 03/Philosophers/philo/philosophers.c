/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramartin <ramartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:53:29 by ramartin          #+#    #+#             */
/*   Updated: 2023/08/22 16:59:43 by ramartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_error_handling(int error_code)
{
	if (error_code == -1)
		write(2, "Memory allocation error.\n", 26);
	if (error_code == 0)
		write(2, "Error: Wrong number of arguments.\n", 35);
	if (error_code == 1)
		write(2, "Error: At least one argument isn't a positive integer.\n", 56);
	if (error_code == 2)
		write(2, "Times and number of philosophers must not be null.\n", 52);
}

int	main(int ac, char **av)
{
	t_philo	simu_data;

	if ((ac == 5) || (ac == 6))
	{
		if (philo_check_input(ac, av) == 1)
		{
			simu_data.philo = ft_atoi(av[1]);
			simu_data.death_time = ft_atoi(av[2]);
			simu_data.eating_time = ft_atoi(av[3]);
			simu_data.sleeping_time = ft_atoi(av[4]);
			if (ac == 5)
				simu_data.times_to_eat = 0;
			else
				simu_data.times_to_eat = ft_atoi(av[5]);
			/*philo_simulation(simu_data);*/
		}
		else if (philo_check_input(ac, av) == 0)
			philo_error_handling(1);
		else
			philo_error_handling(2);
	}
	else
		philo_error_handling(0);
}