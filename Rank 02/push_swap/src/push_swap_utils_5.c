/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_5.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramartin <ramartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:30:18 by ramartin          #+#    #+#             */
/*   Updated: 2022/12/22 18:09:36 by ramartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_chunk_to_b(long *stacka, long *stackb, long h1, long h2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (stacka[i] != h1)
		i++;
	if (h2 != 0)
	{
		while (stacka[j] != h2)
			j++;
	}
	if (h2 != 0)
	{
		
	}
}
