/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_5.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramartin <ramartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:30:18 by ramartin          #+#    #+#             */
/*   Updated: 2023/01/13 11:03:19 by ramartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_return_stack_to_a(long *stacka, long *stackb)
{
	int		i;

	i = 0;
	while (stackb[i] != ps_check_max(stackb))
		i++;
	while (stackb[0])
	{
		while (stackb[0] != ps_check_max(stackb))
		{
			if (i < ((ps_check_arg_num(stackb) - 1) / 2))
				stackb = ps_rb(stackb);
			else
				stackb = ps_rrb(stackb);
		}
		ps_pa(stacka, stackb);
	}
}

int	ps_check_under_lim(long *stacka, long lim)
{
	int	i;

	i = 0;
	while (stacka[i])
	{
		if ((stacka[i] > lim))
			return (1);
		i++;
	}
	return (0);
}

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
