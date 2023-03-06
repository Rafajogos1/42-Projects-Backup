/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_verify_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:47:37 by ramartin          #+#    #+#             */
/*   Updated: 2023/03/06 20:27:30 by rafael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* This function checks how many lines the map has */
int	sl_count_lines(char *map)
{
	int	i;
	int	lines;

	i = 0;
	lines = 1;
	while (map[i++])
		if (map[i] == '\n')
			lines++;
	return (lines);
}

/* This function checks if the walls are only
composed by the character "1" */
int	sl_check_around(char *map)
{
	int	lines;
	int	i;
	int	j;

	lines = sl_count_lines(map);
	i = -1;
	j = 0;
	while (map[++i])
	{
		if (((j == 0) || (j == (lines - 1))) && (map[i] != '\n'))
		{
			if ((map[i] != '1') && ((map[i] != '\0')))
				return (0);
		}
		else
		{
			if ((map[i - 1] == '\n') && (map[i] != '1'))
				return (0);
			if ((map[i + 1] == '\n') && (map[i] != '1'))
				return (0);
		}
		if (map[i] == '\n')
			j++;
	}
	return (1);
}

/* This function checks if the map is a rectangle */
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
	len++;
	while (map[i++])
	{
		if (map[i] == '\n')
		{
			if (j != (len - 1))
				return (0);
			else
				j = -1;
		}
		j++;
	}
	return (sl_check_around(map));
}
