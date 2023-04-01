/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 15:16:35 by rafael            #+#    #+#             */
/*   Updated: 2023/04/01 16:18:54 by rafael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_error_handling(int error_code)
{
	if (error_code == 0)
		write(2, "Error: Wrong number of arguments.\n", 35);
	if (error_code == 1)
		write(2, "Error: At least one argument isn't a positive integer.\n", 56);
}

/*
void	philo_simulation(t_philo simu_data)
{
	
}
*/

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
			printf("%i\n%i\n%i\n%i\n%i\n", simu_data.philo, simu_data.death_time \
			, simu_data.eating_time, simu_data.sleeping_time, simu_data.times_to_eat);
		}
		else
			philo_error_handling(1);
	}
	else
		philo_error_handling(0);
}
