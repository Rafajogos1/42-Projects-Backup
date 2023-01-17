/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramartin <ramartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 09:21:57 by ramartin          #+#    #+#             */
/*   Updated: 2023/01/17 17:00:08 by ramartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* This fucntion is the one that is responsible to
check how many numbers there are and calls the 
correct function to sort them */
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

/* push_swap itself. It calls ps_count to count the numbers
and select the correct sorting algorithm */
void	push_swap(long *stacka, int ac, long *stackcpy)
{
	int		args;

	args = (ac - 1);
	ps_count(stacka, args, stackcpy);
}

/* The main recieves the numbers from the terminal and
creates stack a with them and a copy to calculate the
median, and then passes them to push_swap */
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
