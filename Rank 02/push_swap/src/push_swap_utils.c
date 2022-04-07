/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramartin <ramartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 09:21:57 by ramartin          #+#    #+#             */
/*   Updated: 2022/04/07 11:40:18 by ramartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/* This function creates stack a with the given arguments */
int	*ps_make_stacka(int args, char **input)
{
	int	i;
	int	j;
	int	*stacka;

	i = (args - 1);
	j = 0;
	stacka = malloc(sizeof(int *) * (args - 1));
	if (!stacka)
		return (0);
	while (i > 0 && input[i])
	{
		stacka[j] = ft_atoi(input[i]);
		j++;
		i--;
	}
	return (stacka);
	free (stacka);
}

/* This function creates stack b */
int	*ps_make_stackb(void)
{
	int	*stackb;

	stackb = malloc(sizeof(int *));
	if (!stackb)
		return (0);
	return (stackb);
	free (stackb);
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
