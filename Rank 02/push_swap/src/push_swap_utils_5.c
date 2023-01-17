/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_5.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramartin <ramartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:30:18 by ramartin          #+#    #+#             */
/*   Updated: 2023/01/17 16:57:13 by ramartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* This function puts the previous chunk on top of the stack */
long	*ps_put_chunk_on_top(long *stacka, long num)
{
	int	i;
	int	inst;

	i = 0;
	inst = 0;
	while (stacka[i] != num)
		i++;
	if (i < ((ps_check_arg_num(stacka) - 1) / 2))
	{
		i = (ps_check_arg_num(stacka) - 1);
		inst = 1;
	}
	if (num != 0)
	{
		while (stacka[0] != num)
		{
			if (inst == 0)
				stacka = ps_rra(stacka);
			else
				stacka = ps_ra(stacka);
		}
	}
	return (stacka);
}

/* This function returns the chunk back to stacka a*/
void	ps_return_stack_to_a(long *stacka, long *stackb, long num)
{
	int		i;

	i = 0;
	ps_put_chunk_on_top(stacka, num);
	while (stackb[0])
	{
		while (stackb[i] < stackb[i + 1])
			i++;
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

/* This function checks if a number over the limit exists */
int	ps_check_over_lim(long *stacka, long lim, long lim2)
{
	int	i;

	i = 0;
	while (stacka[i])
	{
		if ((stacka[i] >= lim) && (stacka[i] < lim2))
			return (1);
		i++;
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
