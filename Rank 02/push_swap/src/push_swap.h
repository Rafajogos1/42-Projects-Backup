/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramartin <ramartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 09:21:57 by ramartin          #+#    #+#             */
/*   Updated: 2022/04/26 16:55:33 by ramartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

/* Instructions */
int		*ps_sa(int *stacka);
int		*ps_sb(int *stackb);
void	ps_ss(int *stacka, int *stackb);
void	ps_pa(int *stacka, int *stackb);
void	ps_pb(int *stacka, int *stackb);
int		*ps_ra(int	*stacka);
int		*ps_rb(int	*stackb);
void	ps_rr(int *stacka, int *stackb);
int		*ps_rra(int *stacka);
int		*ps_rrb(int *stackb);
void	ps_rrr(int *stacka, int *stackb);

/* Utils */
int		ps_check_arg_num(int *stack);
int		*ps_make_stacka(int args, char **input);
int		*ps_make_stackb(int args);
int		*ps_push(int *stack);
int		*ps_push_rev(int *stack);

/* Verify */
int		ps_check_if_int(char *input);
int		ps_check_if_repeat(int args, char **input);
int		ps_check_input(int args, char **input);
int		ps_check_int_limits(int len, char *input);

#endif