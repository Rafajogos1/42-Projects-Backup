/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramartin <ramartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 09:21:57 by ramartin          #+#    #+#             */
/*   Updated: 2022/04/27 12:10:08 by ramartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

/* push_swap */
void	push_swap(int *stacka, int args);
void	ps_count(int *stacka, int args);
void	ps_two(int *stacka);
void	ps_three(int *stacka);

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

/* Utililties */
int		ps_check_arg_num(int *stack);
int		*ps_make_stacka(int args, char **input);
int		*ps_make_stackb(int args);
int		*ps_push(int *stack);
int		*ps_push_rev(int *stack);
int		ps_check_sort(int *stacka);

/* Verify */
int		ps_check_if_int(char *input);
int		ps_check_if_repeat(int args, char **input);
int		ps_check_input(int args, char **input);
int		ps_check_int_limits(int len, char *input);
int		ps_check_quotes(char *input);

#endif