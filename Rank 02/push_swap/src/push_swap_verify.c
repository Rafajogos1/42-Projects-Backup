/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_verify.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramartin <ramartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 09:21:57 by ramartin          #+#    #+#             */
/*   Updated: 2023/01/13 21:24:58 by ramartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* This function checks if the argument is between 
the minimum and the maximum values of an integer */
int	ps_check_int_limits(int len, char *input)
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
int	ps_check_if_int(char *input)
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
		if (ps_check_int_limits(ft_strlen(input), input) == 0)
			return (0);
	}
	if (ft_atoi(input))
		return (1);
	else
		return (0);
}

/* This function checks if the same number appears more than once */
int	ps_check_if_repeat(int args, char **input)
{
	int	i;
	int	j;

	i = (args - 1);
	while (i > 0)
	{
		j = (i - 1);
		while (j > 0)
		{
			if (ft_strncmp(input[i], input[j], 11) == 0)
				return (0);
			j--;
		}
		i--;
	}
	return (1);
}

/* This function checks if the input is valid*/
int	ps_check_input(int args, char **input)
{
	int	i;

	i = (args - 1);
	while (i > 0 && input[i])
	{
		if (!(ps_check_if_int(input[i]) == 1))
			return (0);
		else
			i--;
	}
	if (!(ps_check_if_repeat(args, input) == 1))
		return (0);
	else
		return (1);
}
