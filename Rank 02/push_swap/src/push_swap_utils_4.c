/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramartin <ramartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:30:18 by ramartin          #+#    #+#             */
/*   Updated: 2023/01/13 11:07:49 by ramartin         ###   ########.fr       */
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
long	*ps_lims(long *stackcpy, long *lims, int chunks, int i)
{
	if (chunks == 5)
	{
		lims[0] = -2147483650;
		lims[1] = stackcpy[i / 2];
		lims[2] = stackcpy[i];
		lims[3] = stackcpy[i + (i / 2)];
	}
	else
	{
		lims[0] = -2147483650;
		lims[1] = stackcpy[i / 5];
		lims[2] = stackcpy[2 * (i / 5)];
		lims[3] = stackcpy[3 * (i / 5)];
		lims[4] = stackcpy[4 * (i / 5)];
		lims[5] = stackcpy[i];
		lims[6] = stackcpy[i + ((i / 5))];
		lims[7] = stackcpy[i + 2 * ((i / 5))];
		lims[8] = stackcpy[i + 3 * ((i / 5))];
		lims[9] = stackcpy[i + 4 * ((i / 5))];
	}
	return (lims);
}

/* This function searches from the top the first number under the limit */
long	ps_h1(long *stacka, long lim)
{
	int		i;

	i = 0;
	while (stacka[i])
	{
		if ((stacka[i] > lim))
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
		if ((stacka[i] > lim))
			return (stacka[i]);
		i--;
	}
	return (0);
}
