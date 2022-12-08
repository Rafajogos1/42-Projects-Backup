/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramartin <ramartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 09:21:57 by ramartin          #+#    #+#             */
/*   Updated: 2022/12/06 19:02:20 by ramartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

long	ps_check_first_bigger(long *stacka, long num)
{
	int		i;

	i = 1;
	while (stacka[i])
	{
		if (stacka[i] > num)
			return (stacka[i]);
		i++;
	}
	return (stacka[0]);
}

/* Thank you Norminette */
void	ps_five_helper_3(long *stacka, long *stackb)
{
	long	num;
	int		i;

	num = ps_check_first_bigger(stacka, stackb[0]);
	i = 0;
	while (stacka[i] != num)
		i++;
	if (i < 2)
	{
		while (stacka[0] != num)
			stacka = ps_ra(stacka);
	}
	else
	{
		while (stacka[0] != num)
			stacka = ps_rra(stacka);
	}
	ps_pa(stacka, stackb);
}
