/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_pathfinding_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:52:41 by rafael            #+#    #+#             */
/*   Updated: 2023/02/19 23:11:06 by rafael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* This function counts how many collectibles exist. */
int	sl_count_char_2(char **map_grid)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	j = 0;
	c = 0;
	while (map_grid[i][j])
	{
		if ((map_grid[i][j] == 'C') || (map_grid[i][j] == 'E') \
		|| (map_grid[i][j] == 'P'))
			c++;
		if ((map_grid[i][j] == '\0') || (map_grid[i][j] == '\n'))
		{
			i++;
			j = 0;
		}
		j++;
	}
	if (c == 0)
		return (1);
	return (0);
}

/* This function counts the walkable characters. */
int	sl_count_walkable(char **map_grid)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 1;
	while (map_grid[i][j])
	{
		if ((map_grid[i][j] == '0') || (map_grid[i][j] == 'C'))
			count++;
		if ((map_grid[i][j] == '\0') || (map_grid[i][j] == '\n'))
		{
			i++;
			j = 0;
		}
		j++;
	}
	return (count);
}

/* This function checks if the character is walkable and turns it into "-". */
void	sl_check_next_to(char **map_grid, int *i, int *j)
{
	if ((map_grid[*i + 1][*j] == '0') || (map_grid[*i + 1][*j] == 'E') \
	|| (map_grid[*i + 1][*j] == 'C'))
		map_grid[*i + 1][*j] = '-';
	if ((map_grid[*i - 1][*j] == '0') || (map_grid[*i - 1][*j] == 'E') \
	|| (map_grid[*i - 1][*j] == 'C'))
		map_grid[*i - 1][*j] = '-';
	if ((map_grid[*i][*j + 1] == '0') || (map_grid[*i][*j + 1] == 'E') \
	|| (map_grid[*i][*j + 1] == 'C'))
		map_grid[*i][*j + 1] = '-';
	if ((map_grid[*i][*j - 1] == '0') || (map_grid[*i][*j - 1] == 'E') \
	|| (map_grid[*i][*j - 1] == 'C'))
		map_grid[*i][*j - 1] = '-';
}

/* This function does a grid version of the map string */
char	**sl_map_grid(int fd, char *map)
{
	int		i;
	char	*buf;
	char	**map_grid;

	i = 0;
	map_grid = malloc(sizeof(char **) * (sl_count_lines(map) + 1));
	if (!map_grid)
		return (NULL);
	while (fd)
	{
		buf = get_next_line(fd);
		if (buf != NULL)
		{
			map_grid[i] = malloc(ft_strlen(buf) + 1);
			map_grid[i] = ft_strncpy(map_grid[i], buf, ft_strlen(buf));
			free(buf);
			i++;
		}
		else
			break ;
	}
	map_grid[i] = NULL;
	return (map_grid);
}
