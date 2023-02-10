/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_hooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 21:04:07 by rafael            #+#    #+#             */
/*   Updated: 2023/02/10 02:16:15 by rafael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*void	sl_find_p(t_map *map, int *x, int *y)
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

int	sl_check_collision(t_map *map, int keycode)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	sl_find_p(map, &x, &y);
	if ((keycode == 119) && (map->map[y - 1][x] == '1'))
		return (1);
	if ((keycode == 97) && (map->map[y][x - 1] == '1'))
		return (1);
	if ((keycode == 100) && (map->map[y][x + 1] == '1'))
		return (1);
	if ((keycode == 115) && (map->map[y + 1][x] == '1'))
		return (1);
	return (0);
}

void	sl_move(t_game *game, int keycode)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	sl_find_p(game->map, &x, &y);
	if ((keycode == 119) && (sl_check_collision(game->map, keycode) == 0))
	{
		game->map->map[y - 1][x] = 'P';
		game->map->map[y][x] = '0';
		sl_start_sprites(game->map, game->game);
		sl_print_map(game);
	}
}*/

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 65307)
		sl_end_game(game);
	/*else
		sl_move(game, keycode);*/
	ft_printf("%i\n", keycode);
	return (0);
}
