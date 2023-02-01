/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_pathfinding.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 22:23:09 by rafael            #+#    #+#             */
/*   Updated: 2023/02/01 22:23:13 by rafael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_count_collectibles(char *map)
{
	int	i;
	int	c;

	i = 0;
	while (map[i++])
		if (map[i] == 'C')
			c++;
	return (c);
}

void	sl_free_grid(char **map_grid)
{
	int	i;

	i = 0;
	while (map_grid[i])
		free(map_grid[i++]);
	free(map_grid);
}

int	sl_pathfinding(int fd, char *map)
{
	char	**map_grid;

	map_grid = sl_map_grid(fd, map);
	sl_free_grid(map_grid);
	free(map);
	return (0);
}
