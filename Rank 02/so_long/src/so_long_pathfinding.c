/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_pathfinding.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 22:23:09 by rafael            #+#    #+#             */
/*   Updated: 2023/02/19 23:10:07 by rafael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* This funciton turns all walkable characters adjacent to every "-" present.
The check is repeated for the number of walkable chracters to ensure that a 
verification is done for every character.*/
void	sl_turn_to_minus(char **map_grid)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = sl_count_walkable(map_grid);
	while (count != 0)
	{
		i = 0;
		j = 0;
		while (map_grid[i][j])
		{
			if (map_grid[i][j] == '-')
				sl_check_next_to(map_grid, &i, &j);
			if ((map_grid[i][j] == '\0') || (map_grid[i][j] == '\n'))
			{
				i++;
				j = 0;
			}
			j++;
		}
		count--;
	}
}

/* This function checks for "P" and turns it into a "-". */
void	sl_start_coordinates(char **map_grid, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map_grid[i][j])
	{
		if ((map_grid[i][j] == '\0') || (map_grid[i][j] == '\n'))
		{
			i++;
			j = 0;
		}
		if (map_grid[i][j] == 'P')
		{
			*x = j;
			*y = i;
			break ;
		}
		j++;
	}
	map_grid[*y][*x] = '-';
}

/* This function turns every walkable character adjacent to a "-". */
void	sl_check_path(char **map_grid)
{
	int	x;
	int	y;

	sl_start_coordinates(map_grid, &x, &y);
	sl_turn_to_minus(map_grid);
}

/* This function frees the grid. */
void	sl_free_grid(char **map_grid)
{
	int	i;

	i = 0;
	while (map_grid[i])
		free(map_grid[i++]);
	free(map_grid);
}

/* This function is responsible for checking if the map has
a valid path. */
int	sl_pathfinding(int fd, char *map)
{
	char	**map_grid;

	map_grid = sl_map_grid(fd, map);
	sl_check_path(map_grid);
	if (sl_count_char_2(map_grid) == 1)
	{
		sl_free_grid(map_grid);
		return (1);
	}
	else
	{
		sl_free_grid(map_grid);
		free(map);
		return (0);
	}
}
