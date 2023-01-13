/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramartin <ramartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 09:21:57 by ramartin          #+#    #+#             */
/*   Updated: 2023/01/13 21:08:22 by ramartin         ###   ########.fr       */
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

/* This function checks the number that comes after num */
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

/* This function checks if the original stack a is already sorted */
int	ps_check_sort(long *stacka)
{
	int	i;
	int	sort;

	i = 0;
	sort = 1;
	while (stacka[i])
	{
		if ((stacka[i] > stacka[i + 1]) && stacka[i + 1] != 0)
			sort = 0;
		i++;
	}
	if (sort == 0)
		return (0);
	else
		return (1);
}

/* This fucntion calculates the appropiate chunk limits*/
long	*ps_chunk_limits(long *stackcpy, int chunks)
{
	int		args;
	long	*lims;
	int		i;

	i = 0;
	args = ps_check_arg_num(stackcpy);
		lims = malloc(sizeof(long *) * chunks);
	if (!lims)
		return (0);
	while (ps_check_sort(stackcpy) == 0)
		ps_sort(stackcpy);
	if ((args % 2) == 0)
		i = (((args / 2 - 1) + (args / 2)) / 2);
	else
		i = (args / 2);
	lims = ps_lims(stackcpy, lims, chunks, i);
	return (lims);
}
