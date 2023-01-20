/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramartin <ramartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 09:21:57 by ramartin          #+#    #+#             */
/*   Updated: 2023/01/20 17:26:25 by ramartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* This function checks the number that comes after num */
long	ps_check_first_bigger(long *stacka, long num)
{
	int		i;

	i = 1;
	while (stacka[i])
	{
		if (stacka[i] > num)
			return (stacka[i]);
		i++;
	}
	return (stacka[0]);
}

/* This function helps ps_sort */
void	ps_swap(long *a, long *b)
{
	long	c;

	c = *a;
	*a = *b;
	*b = c;
}

/* This function sorts a stack (it is only used to get the median) */
void	ps_sort(long *stack)
{
	int	i;
	int	s;

	i = 0;
	s = 0;
	while (stack[i])
	{
		if (stack[i] > stack[i + 1])
		{
			ps_swap(&stack[i], &stack[i + 1]);
			s = 1;
		}
		if (s == 1)
			break ;
		i++;
	}
}

/* This function checks if the stack is already sorted */
int	ps_check_sort(long *stacka)
{
	int	i;
	int	sort;

	i = 0;
	sort = 1;
	while (stacka[i])
	{
		if ((stacka[i] > stacka[i + 1]) && stacka[i + 1] != 0)
			sort = 0;
		i++;
	}
	if (sort == 0)
		return (0);
	else
		return (1);
}

/* This fucntion calculates the appropiate chunk limits*/
long	*ps_chunk_limits(long *stackcpy, int chunks)
{
	int		args;
	long	*lims;
	int		i;

	i = 0;
	args = ps_check_arg_num(stackcpy);
		lims = malloc(sizeof(long *) * chunks);
	if (!lims)
		return (0);
	while (ps_check_sort(stackcpy) == 0)
		ps_sort(stackcpy);
	if ((args % 2) == 0)
		i = (((args / 2 - 1) + (args / 2)) / 2);
	else
		i = (args / 2);
	lims = ps_lims(stackcpy, lims, chunks, i);
	return (lims);
}
