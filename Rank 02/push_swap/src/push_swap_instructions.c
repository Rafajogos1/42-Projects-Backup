/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_instructions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramartin <ramartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 09:21:57 by ramartin          #+#    #+#             */
/*   Updated: 2023/01/13 10:49:37 by ramartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* sa (swap a)*/
long	*ps_sa(long *stacka)
{
	int	i;

	if (ps_check_arg_num(stacka) > 1)
	{
		i = stacka[0];
		stacka[0] = stacka[1];
		stacka[1] = i;
	}
	ft_printf("sa\n");
	return (stacka);
}

/* sb (swap b) */
long	*ps_sb(long *stackb)
{
	int	i;

	if (ps_check_arg_num(stackb) > 1)
	{
		i = stackb[0];
		stackb[0] = stackb[1];
		stackb[1] = i;
	}
	ft_printf("sb\n");
	return (stackb);
}

/* ss (sa and sb at the same time) */
void	ps_ss(long *stacka, long *stackb)
{
	stacka = ps_sa(stacka);
	stackb = ps_sb(stackb);
	ft_printf("ss\n");
}

/* pa (push a) */
void	ps_pa(long *stacka, long *stackb)
{
	long	btop;

	if (ps_check_arg_num(stackb) > 0)
	{
		btop = stackb[0];
		stacka = ps_push(stacka);
		stacka[0] = btop;
		stackb = ps_push_rev(stackb);
	}
	ft_printf("pa\n");
}

/* pb (push b) */
void	ps_pb(long *stacka, long *stackb)
{
	long	atop;

	if (ps_check_arg_num(stacka) > 0)
	{
		atop = stacka[0];
		stackb = ps_push(stackb);
		stackb[0] = atop;
		stacka = ps_push_rev(stacka);
	}
	ft_printf("pb\n");
}
