/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramartin <ramartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 09:21:57 by ramartin          #+#    #+#             */
/*   Updated: 2022/12/22 17:43:29 by ramartin         ###   ########.fr       */
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

/* This function checks the number that comes after num*/
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

/* This fucntion calculates the appropiate chunk limits*/
long	*ps_chunk_limits(long *stacka, int chunks)
{
	int		args;
	long	median;
	long	*stack;
	long	*lims;

	args = ps_check_arg_num(stacka);
	stack = stacka;
	lims = malloc(sizeof(long *) * (chunks - 1));
	if (!lims)
		return (0);
	while (ps_check_sort(stack) == 0)
		ps_sort(stack);
	if ((args % 2) == 0)
	{
		median = ((stacka[(args / 2)] + stacka[(args / 2) + 1]) / 2);
	}
	else
		median = (stacka[(args / 2)]);
	ps_lims(lims, chunks, median, ps_check_max(stacka));
	return (lims);
}
