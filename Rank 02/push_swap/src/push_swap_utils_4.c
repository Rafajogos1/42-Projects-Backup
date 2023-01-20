/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramartin <ramartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:30:18 by ramartin          #+#    #+#             */
/*   Updated: 2023/01/20 17:26:49 by ramartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* This function assigns the limits to the lims array */
long	*ps_lims(long *stackcpy, long *lims, int chunks, int i)
{
	if (chunks == 5)
	{
		lims[0] = -2147483650;
		lims[1] = stackcpy[i / 2];
		lims[2] = stackcpy[i];
		lims[3] = stackcpy[i + (i / 2)];
		lims[4] = (ps_check_max(stackcpy) + 1);
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
		lims[10] = (ps_check_max(stackcpy) + 1);
	}
	return (lims);
}

/* This function searches from the top the first number under the limit */
long	ps_h1(long *stacka, long lim, long lim2)
{
	int		i;

	i = 0;
	while (stacka[i])
	{
		if ((stacka[i] >= lim) && (stacka[i] < lim2))
			return (stacka[i]);
		i++;
	}
	return (0);
}

/* This function searches from the bottom the first number under the limit */
long	ps_h2(long *stacka, long lim, long lim2)
{
	int		i;

	i = (ps_check_arg_num(stacka) - 1);
	while (stacka[i])
	{
		if ((stacka[i] >= lim) && (stacka[i] < lim2))
			return (stacka[i]);
		i--;
	}
	return (0);
}

/* This function rotates the number to the top of the stack 
and then passes it to stack b */
void	ps_rotate(long *stacka, long *stackb, int d1, int d2)
{
	if (d1 <= d2)
	{
		while (d1 != 0)
		{
			stacka = ps_ra(stacka);
			d1--;
		}
	}
	else
	{
		while (d2 != 0)
		{
			stacka = ps_rra(stacka);
			d2--;
		}
	}
	ps_pb(stacka, stackb);
}

/* This function passes the current chunk to stack b */
void	ps_chunk_to_b(long *stacka, long *stackb, long h1, long h2)
{
	int	i;
	int	j;
	int	d1;
	int	d2;

	i = 0;
	j = 0;
	while (stacka[i] != h1)
		i++;
	d1 = i;
	while (stacka[j] != h2)
		j++;
	if (j <= ((ps_check_arg_num(stacka) - 1) / 2))
		d2 = j;
	else
		d2 = (ps_check_arg_num(stacka) - j);
	ps_rotate(stacka, stackb, d1, d2);
}
