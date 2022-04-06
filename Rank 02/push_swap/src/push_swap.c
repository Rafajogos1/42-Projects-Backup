/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramartin <ramartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 09:21:57 by ramartin          #+#    #+#             */
/*   Updated: 2022/04/06 13:36:37 by ramartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_check_if_int(char *input)
{
	int		i;
	int		num;

	i = 0;
	while (input[i] != '\0')
	{
		if (!(input[i] >= 48 && input[i] <= 57))
			return (0);
		i++;
	}
	if (num > 2147483647 || num < -2147483648)
		return (0);
	else
		return (1);
}

int	*ps_check_input(int args, char **input)
{
	int	i;
	int	j;
	int	num;
	int	*stacka;

	i = (args - 1);
	j = 0;
	while (i > 0)
	{
		if (ps_check_if_int(input[i]))
		{
			
		}
		else
		{
			write(2, "Error\n", 6);
			break ;
		}
	}
	return (stacka);
}

int	main(int argc, char **argv)
{
	int	*stacka;

	if (argc >= 2)
	{
		if (ps_check_input(argc, argv))
		{
			stacka = ps_check_input(argc, argv);
		}
	}
	return (0);
}
