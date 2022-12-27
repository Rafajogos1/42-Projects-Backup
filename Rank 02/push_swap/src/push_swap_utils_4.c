/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramartin <ramartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:30:18 by ramartin          #+#    #+#             */
/*   Updated: 2022/12/27 17:36:46 by ramartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* This function helps ps_sort */
void	ps_swap(long *a, long *b)
{
	long	c;

	c = *a;
	*a = *b;
	*b = c;
}

/* This function sorts a stack (it is only used to get the median) */
void	ps_sort(long *stack)
{
	int	i;
	int	s;

	i = 0;
	s = 0;
	while (stack[i])
	{
		if (stack[i] > stack[i + 1])
		{
			ps_swap(&stack[i], &stack[i + 1]);
			s = 1;
		}
		if (s == 1)
			break ;
		i++;
	}
}

/* This function assigns the limits to the lims array */
void	ps_lims(long *lims, int chunks, long median, long big)
{
	if (chunks == 5)
	{
		lims[0] = (median / 2);
		lims[1] = median;
		lims[2] = (median + (median / 2));
		lims[3] = big;
	}
	else
	{
		lims[0] = (median / 5);
		lims[1] = (2 * (median / 5));
		lims[2] = (3 * (median / 5));
		lims[3] = (4 * (median / 5));
		lims[4] = median;
		lims[5] = (median + ((median / 5)));
		lims[6] = (median + 2 * ((median / 5)));
		lims[7] = (median + 3 * ((median / 5)));
		lims[8] = (median + 4 * ((median / 5)));
		lims[9] = big;
	}
}

/* This function searches from the top the first number under the limit */
long	ps_h1(long *stacka, long lim)
{
	int		i;

	i = 0;
	while (stacka[i])
	{
		if (stacka[i] <= lim)
			return (stacka[i]);
		i++;
	}
	return (0);
}

/* This function searches from the bottom the first number under the limit */
long	ps_h2(long *stacka, long lim)
{
	int		i;

	i = (ps_check_arg_num(stacka) - 1);
	while (stacka[i])
	{
		if (stacka[i] <= lim)
			return (stacka[i]);
		i--;
	}
	return (0);
}
