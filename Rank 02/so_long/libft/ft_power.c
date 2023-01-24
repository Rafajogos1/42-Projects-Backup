/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramartin <ramartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 17:09:36 by ramartin          #+#    #+#             */
/*   Updated: 2022/12/10 17:09:36 by ramartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_power(int num, int power)
{
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else
		return (num * ft_power(num, power - 1));
}
