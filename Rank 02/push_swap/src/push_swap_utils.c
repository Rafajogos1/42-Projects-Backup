/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramartin <ramartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 09:21:57 by ramartin          #+#    #+#             */
/*   Updated: 2022/04/20 12:46:05 by ramartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/* This function creates stack a with the given arguments */
int	*ps_make_stacka(int args, char **input)
{
	int	i;
	int	j;
	int	*stacka;

	i = 1;
	j = 0;
	stacka = malloc(sizeof(int *) * (args - 1));
	if (!stacka)
		return (0);
	while (i < args && input[i])
	{
		stacka[j] = ft_atoi(input[i]);
		j++;
		i++;
	}
	return (stacka);
}

/* This function creates stack b */
int	*ps_make_stackb(int args)
{
	int	*stackb;

	stackb = malloc(sizeof(int *) * (args - 1));
	if (!stackb)
		return (0);
	return (stackb);
}

/* This function checks the number of arguments in the stack */
int	ps_check_arg_num(int *stack)
{
	int	i;

	i = 0;
	while (stack[i])
		i++;
	return (i);
}

/* This function increases all the elements indexes by one
and sets the firt one (index = 0) to 1 (only as a placeholder) */
int	*ps_push(int *stack)
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
int	*ps_push_rev(int *stack)
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
