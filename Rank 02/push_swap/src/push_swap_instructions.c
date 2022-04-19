/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_instructions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramartin <ramartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 09:21:57 by ramartin          #+#    #+#             */
/*   Updated: 2022/04/07 11:54:19 by ramartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ps_ss(int *stacka, int *stackb)
{
	stacka = ps_sa(stacka);
	stackb = ps_sb(stackb);
}
