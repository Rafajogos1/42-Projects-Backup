/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_5.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramartin <ramartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:30:18 by ramartin          #+#    #+#             */
/*   Updated: 2023/01/02 17:32:49 by ramartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_rotate_helper(long *stacka, long *stackb)
{
	if (stacka[0] > stackb[0])
		ps_pb(stacka, stackb);
	else if (stacka[0] < stackb[ps_check_arg_num(stackb) - 1])
	{
		ps_pb(stacka, stackb);
		stackb = ps_rb(stackb);
	}
	else
	{
		while (stackb[0] > stacka[0])
			stackb = ps_rb(stackb);
		ps_pb(stacka, stackb);
	}
}

void	ps_rotate(long *stacka, long *stackb, int d1, int d2)
{
	if (d1 < d2)
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
	ps_rotate_helper(stacka, stackb);
	while (ps_check_max(stackb) != stackb[0])
		stackb = ps_rrb(stackb);
}

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
	if (h2 != 0)
	{
		while (stacka[j] != h2)
			j++;
		if (i <= ((ps_check_arg_num(stacka) - 1) / 2))
			d2 = j;
		else
			d2 = (ps_check_arg_num(stacka) - j);
	}
	if (h2 != 0)
		ps_rotate(stacka, stackb, d1, d2);
}
