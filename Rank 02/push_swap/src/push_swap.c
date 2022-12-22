/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramartin <ramartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 09:21:57 by ramartin          #+#    #+#             */
/*   Updated: 2022/12/12 17:37:53 by ramartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_count(long *stacka, int args)
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
		ps_hundred(stacka, stackb);
}

void	push_swap(long *stacka, int ac)
{
	int		args;

	args = (ac - 1);
	ps_count(stacka, args);
}

int	main(int argc, char **argv)
{
	long	*stacka;

	if (argc >= 2)
	{
		if (ps_check_input(argc, argv) == 1)
		{
			stacka = ps_make_stacka(argc, argv);
			if (ps_check_sort(stacka) == 0)
				push_swap(stacka, argc);
		}
		else
			write(2, "Error\n", 6);
	}
	free(stacka);
}
