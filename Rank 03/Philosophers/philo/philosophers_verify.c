/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_verify.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 15:51:18 by rafael            #+#    #+#             */
/*   Updated: 2023/04/01 16:19:29 by rafael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* These functions were adapted from my verify funtions of push_swap. */

/* This function checks if the number fits in an int. */
int	philo_check_int_limits(int len, char *input)
{
	int	k;

	k = 0;
	if (len > 11)
		return (0);
	else if (len == 11 && !(input[0] == '+' || input[0] == '-'))
		return (0);
	if (input[0] == '-' || input[0] == '+')
	{
		if (input[0] == '-')
			k = ft_strncmp ("-2147483648", input, 12);
		if (input[0] == '+')
			k = ft_strncmp ("+2147483647", input, 12);
	}
	else
		k = ft_strncmp ("2147483647", input, 11);
	if (k < 0)
		return (0);
	else
		return (1);
}

/* This function checks if the argument is an integer */
int	philo_check_if_int(char *input)
{
	int	i;

	i = 0;
	if ((input[i] == '0'))
		return (1);
	while (input[i] != '\0')
	{
		if (!((input[i] >= 48 && input[i] <= 57) || input[0] == '-' \
		|| input[0] == '+'))
			return (0);
		i++;
	}
	if (ft_strlen(input) >= 10)
	{
		if (philo_check_int_limits(ft_strlen(input), input) == 0)
			return (0);
	}
	if (ft_atoi(input))
		return (1);
	else
		return (0);
}

/* This function checks if the input is valid also checking
if the value is positive */
int	philo_check_input(int args, char **input)
{
	int	i;

	i = (args - 1);
	while (i > 0 && input[i])
	{
		if (!(philo_check_if_int(input[i]) == 1))
			return (0);
		if (ft_atoi(input[i]) < 0)
			return (0);
		else
			i--;
	}
	return (1);
}
