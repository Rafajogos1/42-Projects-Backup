/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_instructions_2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramartin <ramartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 09:21:57 by ramartin          #+#    #+#             */
/*   Updated: 2022/04/20 13:09:30 by ramartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ra */
int	*ps_ra(int	*stacka)
{
	int	num;
	int	args;

	num = stacka[0];
	args = (ps_check_arg_num(stacka) - 1);
	if (ps_check_arg_num(stacka) > 1)
	{
		stacka = ps_push_rev(stacka);
		stacka[args] = num;
	}
	return (stacka);
}

/* rb */
int	*ps_rb(int	*stackb)
{
	int	num;
	int	args;

	num = stackb[0];
	args = (ps_check_arg_num(stackb) - 1);
	if (ps_check_arg_num(stackb) > 1)
	{
		stackb = ps_push_rev(stackb);
		stackb[args] = num;
	}
	return (stackb);
}
