/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramartin <ramartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 09:21:57 by ramartin          #+#    #+#             */
/*   Updated: 2022/04/20 13:09:51 by ramartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	*stacka;
	int	*stackb;
	int	i;

	if (argc >= 2)
	{
		if (ps_check_input(argc, argv) == 1)
		{
			stacka = ps_make_stacka(argc, argv);
			stackb = ps_make_stackb(argc);
			stackb[0] = 10;
			stackb[1] = 20;
			i = 0;
			while (stacka[i])
			{
				ft_printf("%i\n", stacka[i]);
				i++;
			}
			ft_printf("\n");
			i = 0;
			while (stackb[i])
			{
				ft_printf("%i\n", stackb[i]);
				i++;
			}
		}
		else
			write(2, "Error\n", 6);
	}
	free(stacka);
	free(stackb);
}
