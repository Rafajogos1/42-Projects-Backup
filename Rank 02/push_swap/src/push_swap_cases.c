/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cases.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramartin <ramartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 09:21:57 by ramartin          #+#    #+#             */
/*   Updated: 2022/04/27 12:01:08 by ramartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* With two numbers */
void	ps_two(int *stacka)
{
	stacka = ps_sa(stacka);
}

/* With three numbers */
void	ps_three(int *stacka)
{
	if ((stacka[0] > stacka[1]))
	{
		if ((stacka[0] < stacka[2]) && (stacka[1] < stacka[2]))
			stacka = ps_sa(stacka);
		if ((stacka[0] > stacka[2]) && (stacka[1] < stacka[2]))
			stacka = ps_ra(stacka);
		if (stacka[1] > stacka[2])
		{
			stacka = ps_sa(stacka);
			stacka = ps_rra(stacka);
		}
	}
	if ((stacka[0] < stacka[1]))
	{
		if (stacka[0] < stacka[2])
		{
			stacka = ps_sa(stacka);
			stacka = ps_ra(stacka);
		}
		if (stacka[0] > stacka[2])
			stacka = ps_rra(stacka);
	}
}
