/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_hooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramartin <ramartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 21:04:07 by rafael            #+#    #+#             */
/*   Updated: 2023/02/13 18:14:11 by ramartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	sl_move_horizontal(t_game *game, int keycode, int *x, int *y)
{
	if ((keycode == 97) && (sl_check_collision(game->map, keycode) == 0))
	{
		game->map->map[*y][*x - 1] = 'P';
		game->map->map[*y][*x] = '0';
		sl_print_map(game);
	}
	if ((keycode == 100) && (sl_check_collision(game->map, keycode) == 0))
	{
		game->map->map[*y][*x + 1] = 'P';
		game->map->map[*y][*x] = '0';
		sl_print_map(game);
	}
}

void	sl_move_vertical(t_game *game, int keycode, int *x, int *y)
{
	if ((keycode == 115) && (sl_check_collision(game->map, keycode) == 0))
	{
		game->map->map[*y + 1][*x] = 'P';
		game->map->map[*y][*x] = '0';
		sl_print_map(game);
	}
	if ((keycode == 119) && (sl_check_collision(game->map, keycode) == 0))
	{
		game->map->map[*y - 1][*x] = 'P';
		game->map->map[*y][*x] = '0';
		sl_print_map(game);
	}
}

void	sl_move(t_game *game, int keycode)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	sl_find_p(game->map, &x, &y);
	if ((keycode == 119) || (keycode == 115))
		sl_move_vertical(game, keycode, &x, &y);
	if ((keycode == 97) || (keycode == 100))
		sl_move_horizontal(game, keycode, &x, &y);
}

int	key_hook(int keycode, t_game *game)
{
	ft_printf("%i\n", keycode);
	if (keycode == 65307)
	{
		sl_free_sprites(game);
		sl_end_game(game);
	}
	else
		sl_move(game, keycode);
	return (0);
}
