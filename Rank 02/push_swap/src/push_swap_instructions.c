/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_instructions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramartin <ramartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 09:21:57 by ramartin          #+#    #+#             */
/*   Updated: 2022/04/20 12:50:08 by ramartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* sa */
int	*ps_sa(int *stacka)
{
	int	i;

	if (ps_check_arg_num(stacka) > 1)
	{
		i = stacka[0];
		stacka[0] = stacka[1];
		stacka[1] = i;
	}
	return (stacka);
}

/* sb */
int	*ps_sb(int *stackb)
{
	int	i;

	if (ps_check_arg_num(stackb) > 1)
	{
		i = stackb[0];
		stackb[0] = stackb[1];
		stackb[1] = i;
	}
	return (stackb);
}

/* ss */
void	ps_ss(int *stacka, int *stackb)
{
	stacka = ps_sa(stacka);
	stackb = ps_sb(stackb);
}

/* pa */
void	ps_pa(int *stacka, int *stackb)
{
	int	btop;
	int	anum;

	anum = (ps_check_arg_num(stacka) + 1);
	if (ps_check_arg_num(stackb) > 0)
	{
		btop = stackb[0];
		stacka = ps_push(stacka);
		stacka[0] = btop;
		stackb = ps_push_rev(stackb);
	}
}

/* pb */
void	ps_pb(int *stacka, int *stackb)
{
	int	atop;
	int	bnum;

	bnum = (ps_check_arg_num(stackb) + 1);
	if (ps_check_arg_num(stacka) > 0)
	{
		atop = stacka[0];
		stackb = ps_push(stackb);
		stackb[0] = atop;
		stacka = ps_push_rev(stacka);
	}
}
