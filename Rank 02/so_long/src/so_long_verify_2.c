/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_verify_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramartin <ramartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:47:37 by ramartin          #+#    #+#             */
/*   Updated: 2023/01/27 18:47:02 by ramartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_check_around(char *map)
{
	int	i;
	int	j;
	int	lines;

	i = 0;
	j = 0;
	lines = 1;
	while (map[i++])
		if (map[i] == '\n')
			lines++;
	i = 0;
	ft_printf("%i\n", lines);
	while (map[i++])
	{
		ft_printf("line: %i\n", j);
		if (map[i] == '\n')
		{
			if ((map[i - 1] != '1') || (map[i + 1] != '1'))
				return (0);
			j++;
		}
		ft_printf("1\n");
		if (((j == 0) || (j == (lines - 1))) && (map[i] != '1'))
			return (0);
		ft_printf("2\n");
	}
	ft_printf("%i %i\n", lines);
	return (1);
}

int	sl_check_rectangle(char *map)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 1;
	len = 0;
	while (map[len] != '\n')
		len++;
	while (map[i++])
	{
		if (map[i] == '\n')
		{
			if (j != len)
				return (0);
			else
				j = 0;
		}
		j++;
	}
	return (1);
}
