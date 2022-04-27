/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramartin <ramartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 09:21:57 by ramartin          #+#    #+#             */
/*   Updated: 2022/04/27 11:07:19 by ramartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_count(int *stacka, int args)
{
	int		*stackb;

	stackb = ps_make_stackb(args);
	if (args == 2)
		ps_two(stacka);
	if (args == 3)
		ps_three(stacka);
	free(stackb);
}

void	push_swap(int *stacka, int ac)
{
	int		args;

	args = (ac - 1);
	ps_count(stacka, args);
}

int	main(int argc, char **argv)
{
	static int	*stacka;

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
