/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramartin <ramartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 09:21:57 by ramartin          #+#    #+#             */
/*   Updated: 2022/04/27 11:04:19 by ramartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* This function checks if the original stack a is already sorted */
int	ps_check_sort(int *stacka)
{
	int	i;
	int	sort;

	i = 0;
	sort = 1;
	while (stacka[i])
	{
		if ((stacka[i] > stacka[i + 1]) && stacka[i + 1] != 0)
			sort = 0;
		i++;
	}
	if (sort == 0)
		return (0);
	else
		return (1);
}
