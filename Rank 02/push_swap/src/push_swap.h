/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramartin <ramartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 09:21:57 by ramartin          #+#    #+#             */
/*   Updated: 2022/12/06 17:42:39 by ramartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

/* push_swap */
void	push_swap(long *stacka, int args);
void	ps_count(long *stacka, int args);
void	ps_two(long *stacka);
void	ps_three(long *stacka);
void	ps_five(long *stacka, long *stackb);
void	ps_hundred(long *stacka, long *stackb);

/* Instructions */
long	*ps_sa(long *stacka);
long	*ps_sb(long *stackb);
void	ps_ss(long *stacka, long *stackb);
void	ps_pa(long *stacka, long *stackb);
void	ps_pb(long *stacka, long *stackb);
long	*ps_ra(long	*stacka);
long	*ps_rb(long	*stackb);
void	ps_rr(long *stacka, long *stackb);
long	*ps_rra(long *stacka);
long	*ps_rrb(long *stackb);
void	ps_rrr(long *stacka, long *stackb);

/* Utililties */
int		ps_check_arg_num(long *stack);
long	*ps_make_stacka(int args, char **input);
long	*ps_make_stackb(int args);
long	*ps_push(long *stack);
long	*ps_push_rev(long *stack);
int		ps_check_sort(long *stacka);
long	ps_atoi_helper(long num);
long	ps_atoi(const char *str);
void	ps_five_helper(long *stacka, long *stackb);
long	*ps_five_helper_2(long *stacka);
long	ps_check_max(long *stacka);
long	ps_check_min(long *stacka);
long	ps_check_first_bigger(long *stacka, long num);
void	ps_five_helper_3(long *stacka, long *stackb);

/* Verify */
int		ps_check_if_int(char *input);
int		ps_check_if_repeat(int args, char **input);
int		ps_check_input(int args, char **input);
int		ps_check_int_limits(int len, char *input);

#endif