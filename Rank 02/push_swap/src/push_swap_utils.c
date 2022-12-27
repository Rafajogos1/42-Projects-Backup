/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramartin <ramartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 09:21:57 by ramartin          #+#    #+#             */
/*   Updated: 2022/12/27 17:49:18 by ramartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/* This function creates stack a with the given arguments */
long	*ps_make_stacka(int args, char **input)
{
	int		i;
	int		j;
	long	*stacka;

	i = 1;
	j = 0;
	stacka = malloc(sizeof(long *) * args);
	if (!stacka)
		return (0);
	while (i < args && input[i])
	{
		if (input[i])
		stacka[j] = ps_atoi(input[i]);
		j++;
		i++;
	}
	return (stacka);
}

/* This function creates stack b */
long	*ps_make_stackb(int args)
{
	long	*stackb;

	stackb = malloc(sizeof(long *) * args + 1);
	if (!stackb)
		return (0);
	return (stackb);
}

/* This function checks the number of arguments in the stack */
int	ps_check_arg_num(long *stack)
{
	int	i;

	i = 0;
	while (stack[i])
		i++;
	return (i);
}

/* This function increases all the elements indexes by one
and sets the firt one (index = 0) to 1 (only as a placeholder) */
long	*ps_push(long *stack)
{
	int	i;
	int	j;

	i = (ps_check_arg_num(stack) - 1);
	j = (ps_check_arg_num(stack) - 2);
	stack[i + 1] = stack[i];
	while (i >= 0)
	{
		stack[i] = stack[j];
		j--;
		i--;
	}
	stack[0] = 1;
	return (stack);
}

/* This function decreases all the elements indexes by one 
and deletes the first one */
long	*ps_push_rev(long *stack)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (stack[i])
	{
		stack[j] = stack[i];
		j++;
		i++;
	}
	stack[j] = 0;
	return (stack);
}
