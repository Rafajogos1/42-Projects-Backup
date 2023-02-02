/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_pathfinding_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:52:41 by rafael            #+#    #+#             */
/*   Updated: 2023/02/02 18:38:23 by rafael           ###   ########.fr       */
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
	count = 0;
	while (map_grid[i][j])
	{
		if (map_grid[i][j] == '0')
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
