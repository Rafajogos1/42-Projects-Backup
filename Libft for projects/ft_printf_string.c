/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramartin <ramartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 09:21:57 by ramartin          #+#    #+#             */
/*   Updated: 2022/04/06 10:53:15 by ramartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	printf_string(char *out)
{
	int	i;

	i = 0;
	if (out == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	while (out[i])
	{
		write(1, &out[i], 1);
		i++;
	}
	return (i);
}
