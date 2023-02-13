/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_hooks_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramartin <ramartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:48:13 by ramartin          #+#    #+#             */
/*   Updated: 2023/02/13 18:16:33 by ramartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_close_x(t_game *game)
{
	sl_free_sprites(game);
	sl_end_game(game);
	return (0);
}

void	sl_find_p(t_map *map, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->map[i][j])
	{
		if ((map->map[i][j] == '\0') || (map->map[i][j] == '\n'))
		{
			i++;
			j = 0;
		}
		if (map->map[i][j] == 'P')
		{
			*x = j;
			*y = i;
			break ;
		}
		j++;
	}
}
