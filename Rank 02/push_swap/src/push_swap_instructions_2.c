/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_instructions_2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramartin <ramartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 09:21:57 by ramartin          #+#    #+#             */
/*   Updated: 2022/04/27 11:13:10 by ramartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ra (rotate a) */
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
	ft_printf("ra\n");
	return (stacka);
}

/* rb (rotate b) */
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
	ft_printf("rb\n");
	return (stackb);
}

/* rr (ra and rb at the same time) */
void	ps_rr(int *stacka, int *stackb)
{
	stacka = ps_ra(stacka);
	stackb = ps_rb(stackb);
	ft_printf("rr\n");
}

/* rra (reverse rotate a) */
int	*ps_rra(int *stacka)
{
	int	num;
	int	args;

	args = (ps_check_arg_num(stacka) - 1);
	num = stacka[args];
	if (ps_check_arg_num(stacka) > 1)
	{
		ps_push(stacka);
		stacka[args + 1] = 0;
		stacka[0] = num;
	}
	ft_printf("rra\n");
	return (stacka);
}

/* rrb (reverse rotate b) */
int	*ps_rrb(int *stackb)
{
	int	num;
	int	args;

	args = (ps_check_arg_num(stackb) - 1);
	num = stackb[args];
	if (ps_check_arg_num(stackb) > 1)
	{
		ps_push(stackb);
		stackb[args + 1] = 0;
		stackb[0] = num;
	}
	ft_printf("rrb\n");
	return (stackb);
}
