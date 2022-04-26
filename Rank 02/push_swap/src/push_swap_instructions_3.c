/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_instructions_3.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramartin <ramartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 09:21:57 by ramartin          #+#    #+#             */
/*   Updated: 2022/04/26 16:56:54 by ramartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Thank you Norminette */

#include "push_swap.h"

/* rrr */
void	ps_rrr(int *stacka, int *stackb)
{
	stacka = ps_rra(stacka);
	stackb = ps_rrb(stackb);
}
