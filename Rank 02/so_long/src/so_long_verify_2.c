/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_verify_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:47:37 by ramartin          #+#    #+#             */
/*   Updated: 2023/02/01 22:14:03 by rafael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* This function does a grid version of the map string */
char	**sl_map_grid(int fd, char *map)
{
	int		i;
	char	*buf;
	char	**map_grid;

	i = 0;
	map_grid = malloc(sizeof(char **) * sizeof(map));
	if (!map_grid)
		return (NULL);
	while (fd)
	{
		buf = get_next_line(fd);
		if (buf != NULL)
		{
			map_grid[i] = gnl_ft_strjoin(map_grid[i], buf);
			i++;
		}
		else
		{
			free(buf);
			break ;
		}
		free(buf);
	}
	return (map_grid);
}

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
	i = 0;
	j = 0;
	while (map[i++])
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
			{
				free(map);
				return (0);
			}
			else
				j = -1;
		}
		j++;
	}
	return (sl_check_around(map));
}
