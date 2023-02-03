/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_pathfinding_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramartin <ramartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:52:41 by rafael            #+#    #+#             */
/*   Updated: 2023/02/03 18:15:40 by ramartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	sl_count_zeros(char **map_grid)
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
	map_grid = malloc(sizeof(char **) * ft_strlen(map));
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
