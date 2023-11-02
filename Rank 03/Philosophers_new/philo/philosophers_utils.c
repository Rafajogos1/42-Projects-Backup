/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 21:19:39 by rafael            #+#    #+#             */
/*   Updated: 2023/10/27 21:28:51 by rafael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* A recreation of atoi. */
/* @param str The string to convert into an int */
/* @return The resulting number */
int	ft_atoi(const char *str)
{
	int	i;
	int	neg;
	int	num;

	i = 0;
	neg = 1;
	num = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v' \
			|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (num * neg);
}

/* This function checks if the arguments are only numbers. */
/* @param av The argument vector. */
/* @return 1 if all arguments are numbers, 0 if not. */
int	philo_input_checker(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == ' ')
				j++;
			if ((av[i][j] < 48 || av[i][j] > 57))
				return (philo_error_handling(1));
			j++;
		}
		i++;
	}
	return (1);
}
