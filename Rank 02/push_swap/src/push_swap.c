/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramartin <ramartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 09:21:57 by ramartin          #+#    #+#             */
/*   Updated: 2023/01/13 21:10:49 by ramartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_count(long *stacka, int args, long *stackcpy)
{
	long		*stackb;

	stackb = ps_make_stackb(args);
	if (args == 2)
		ps_two(stacka);
	if (args == 3)
		ps_three(stacka);
	if (args > 3 && args <= 5)
		ps_five(stacka, stackb);
	if (args > 5 && args <= 100)
		ps_hundred(stacka, stackb, stackcpy);
	if (args > 100)
		ps_five_hundred(stacka, stackb, stackcpy);
	free(stackb);
}

void	push_swap(long *stacka, int ac, long *stackcpy)
{
	int		args;

	args = (ac - 1);
	ps_count(stacka, args, stackcpy);
}

int	main(int argc, char **argv)
{
	long	*stacka;
	long	*stackcpy;

	if (argc >= 2)
	{
		if (ps_check_input(argc, argv) == 1)
		{
			stacka = ps_make_stacka(argc, argv);
			stackcpy = ps_make_stacka(argc, argv);
			if (ps_check_sort(stacka) == 0)
				push_swap(stacka, argc, stackcpy);
		}
		else
		{
			write(2, "Error\n", 6);
			return (0);
		}
	}
	free(stacka);
	free(stackcpy);
}
