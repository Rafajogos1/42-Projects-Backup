/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramartin <ramartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 09:21:57 by ramartin          #+#    #+#             */
/*   Updated: 2022/04/06 13:36:37 by ramartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int			i;
	int			j;
	int			n;
	static int	*stacka;

	i = 1;
	j = 0;
	if (argc >= 2)
	{
		if (ps_check_input(argc, argv) == 1)
		{
			while (i < argc)
			{
				stacka[j] = ft_atoi(argv[i]);
				i++;
				j++;
			}
			i = 0;
			while (stacka[i])
			{
				ft_printf("Position number %i: %i\n", i, stacka[i]);
				i++;
			}
		}
		else
			write(2, "Error\n", 6);
	}
}
