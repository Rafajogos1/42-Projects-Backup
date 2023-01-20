/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramartin <ramartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 09:21:57 by ramartin          #+#    #+#             */
/*   Updated: 2023/01/20 17:25:24 by ramartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* This function exists due to norminette function line limit */
long	ps_atoi_helper(long num)
{
	if (num > 0)
		return (num);
	else
		return (num - 1);
}

/* This function works the same way as the original atoi,
but it makes all the negative numbers and 0 one value less */
long	ps_atoi(const char *str)
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
	return (ps_atoi_helper(num = num * neg));
}

/* This function puts the remaining numbers back in stacka
when there's 4 or 5 numbers*/
void	ps_five_helper(long *stacka, long *stackb)
{
	int	i;
	
	i = 0;
	while (stacka[i] != ps_check_min(stacka))
		i++;
	while (stacka[0] != ps_check_min(stacka))
	{
		if (i < ((ps_check_arg_num(stacka) - 1) / 2))
			stacka = ps_ra(stacka);
		else
			stacka = ps_rra(stacka);
	}
	ps_pb(stacka, stackb);
}

/* This function checks the biggest member of the stack */
long	ps_check_max(long *stacka)
{
	long	max;
	int		i;

	max = stacka[0];
	i = 0;
	while (stacka[i])
	{
		if (max < stacka[i])
			max = stacka[i];
		i++;
	}
	return (max);
}

/* This function checks the smallest member of the stack */
long	ps_check_min(long *stacka)
{
	long	min;
	int		i;

	min = stacka[0];
	i = 0;
	while (stacka[i])
	{
		if (min > stacka[i])
			min = stacka[i];
		i++;
	}
	return (min);
}
