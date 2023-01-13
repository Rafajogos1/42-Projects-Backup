/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramartin <ramartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 09:21:57 by ramartin          #+#    #+#             */
/*   Updated: 2023/01/13 21:08:07 by ramartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* This function exists due to norminette function line limit */
long	ps_atoi_helper(long num)
{
	if (num > 0)
		return (num);
	else
		return (num - 1);
}

/* This function works the same way as the original atoi,
but it makes all the negative numbers and 0 one value less */
long	ps_atoi(const char *str)
{
	int	i;
	int	neg;
	int	num;

	i = 0;
	neg = 1;
	num = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v' \
			|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (ps_atoi_helper(num = num * neg));
}

/* Thank you Norminette */
long	*ps_five_helper_2(long *stacka)
{
	long	min;
	int		i;

	min = ps_check_min(stacka);
	i = 0;
	while (stacka[i] != min)
		i++;
	if (i < 3)
	{
		while (!(ps_check_min(stacka) == stacka[0]))
			stacka = ps_ra(stacka);
	}
	else
	{
		while (!(ps_check_min(stacka) == stacka[0]))
			stacka = ps_rra(stacka);
	}
	return (stacka);
}

/* Thank you Norminette */
void	ps_five_helper_3(long *stacka, long *stackb)
{
	long	num;
	int		i;

	num = ps_check_first_bigger(stacka, stackb[0]);
	i = 0;
	while (stacka[i] != num)
		i++;
	if (i < 2)
	{
		while (stacka[0] != num)
			stacka = ps_ra(stacka);
	}
	else
	{
		while (stacka[0] != num)
			stacka = ps_rra(stacka);
	}
	ps_pa(stacka, stackb);
}

/* This function puts the remaining numbers back in stacka
when there's 4 or 5 numbers*/
void	ps_five_helper(long *stacka, long *stackb)
{
	int		i;

	i = ps_check_arg_num(stacka);
	if (ps_check_sort(stacka) == 1)
	{
		if ((stackb[0] < stacka[0]) || (stackb[0] > stacka[i - 1]))
			ps_pa(stacka, stackb);
		else
			ps_five_helper_3(stacka, stackb);
	}
	else
		ps_five_helper_3(stacka, stackb);
	ps_five_helper_2(stacka);
}
