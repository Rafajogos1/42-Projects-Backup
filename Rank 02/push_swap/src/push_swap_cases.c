/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cases.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramartin <ramartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 09:21:57 by ramartin          #+#    #+#             */
/*   Updated: 2022/12/05 17:33:20 by ramartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* With two numbers */
void	ps_two(long *stacka)
{
	stacka = ps_sa(stacka);
}

/* With three numbers */
void	ps_three(long *stacka)
{
	if ((stacka[1] < stacka[0]) && (stacka[1] < stacka[2]))
	{
		if (stacka[0] < stacka[2])
			stacka = ps_sa(stacka);
		else
			stacka = ps_ra(stacka);
	}
	if ((stacka[1] < stacka[0]) && (stacka[1] > stacka[2]))
	{
		stacka = ps_sa(stacka);
		stacka = ps_rra(stacka);
	}
	if ((stacka[1] > stacka[0]) && (stacka[1] > stacka[2]))
	{
		if (stacka[0] < stacka[2])
		{
			stacka = ps_sa(stacka);
			stacka = ps_ra(stacka);
		}
		else
			stacka = ps_rra(stacka);
	}
}

/* With five numbers */
void	ps_five(long *stacka, long *stackb)
{
	int	i;

	i = ps_check_arg_num(stacka);
	while (i > 3)
	{
		ps_pb(stacka, stackb);
		i--;
	}
	ps_three(stacka);
	while (stackb[0])
		ps_five_helper(stacka, stackb);
}
