/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_instructions_3.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramartin <ramartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 09:21:57 by ramartin          #+#    #+#             */
/*   Updated: 2022/11/15 17:40:11 by ramartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Thank you Norminette */

#include "push_swap.h"

/* rrr (rra and rrb at the same time) */
void	ps_rrr(long *stacka, long *stackb)
{
	stacka = ps_rra(stacka);
	stackb = ps_rrb(stackb);
	ft_printf("rrr\n");
}
