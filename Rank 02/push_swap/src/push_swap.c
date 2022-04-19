/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramartin <ramartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 09:21:57 by ramartin          #+#    #+#             */
/*   Updated: 2022/04/07 11:54:50 by ramartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	static int	*stacka;
	int			*stackb;
	int			i;

	if (argc > 2)
	{
		if (ps_check_input(argc, argv) == 1)
		{
			stacka = ps_make_stacka(argc, argv);
			stackb = ps_make_stackb();
			stackb[0] = 20;
			stackb[1] = 10;
		}
		else
			write(2, "Error\n", 6);
	}
}
