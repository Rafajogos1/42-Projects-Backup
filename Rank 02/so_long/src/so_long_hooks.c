/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_hooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 21:04:07 by rafael            #+#    #+#             */
/*   Updated: 2023/02/19 22:59:01 by rafael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* This function checks if the intended tile is free. */
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

/* This function and its counterpart exist due to Norminette's
line limit. They check if the intended tile is free and if so,
update the player's position. It also checks for the presence of
the exit so it knows if the player is or was on top of the exit.*/
void	sl_move_horizontal(t_game *game, int keycode, int *x, int *y)
{
	if ((keycode == 97) && (sl_check_collision(game->map, keycode) == 0))
	{
		if (sl_find_e(game->map) == 0)
			game->map->map[*y][*x] = 'E';
		else
			game->map->map[*y][*x] = '0';
		game->map->map[*y][*x - 1] = 'P';
	}
	if ((keycode == 100) && (sl_check_collision(game->map, keycode) == 0))
	{
		if (sl_find_e(game->map) == 0)
			game->map->map[*y][*x] = 'E';
		else
			game->map->map[*y][*x] = '0';
		game->map->map[*y][*x + 1] = 'P';
	}
}

/* This function and its counterpart exist due to Norminette's
line limit. They check if the intended tile is free and if so,
update the player's position. It also checks for the presence of
the exit so it knows if the player is or was on top of the exit.*/
void	sl_move_vertical(t_game *game, int keycode, int *x, int *y)
{
	if ((keycode == 115) && (sl_check_collision(game->map, keycode) == 0))
	{
		if (sl_find_e(game->map) == 0)
			game->map->map[*y][*x] = 'E';
		else
			game->map->map[*y][*x] = '0';
		game->map->map[*y + 1][*x] = 'P';
	}
	if ((keycode == 119) && (sl_check_collision(game->map, keycode) == 0))
	{
		if (sl_find_e(game->map) == 0)
			game->map->map[*y][*x] = 'E';
		else
			game->map->map[*y][*x] = '0';
		game->map->map[*y - 1][*x] = 'P';
	}
}

/* This function is responsible for the movement. It also
prints the number of movements and checks if the player is
reaching the exit to early. If the player has collected all
the collectibles, the game ends, congratulating the player*/
void	sl_move(t_game *game, int keycode)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	sl_find_p(game->map, &x, &y);
	if ((keycode == 97) || (keycode == 100))
		sl_move_horizontal(game, keycode, &x, &y);
	if ((keycode == 115) || (keycode == 119))
		sl_move_vertical(game, keycode, &x, &y);
	if (sl_find_e(game->map) == 0)
	{
		if (sl_find_c(game->map) == 0)
		{
			ft_printf("Congratulations!\nYou have finnished the game!\n");
			sl_free_sprites(game);
			sl_end_game(game);
		}
		else
			ft_printf("Collect all the collectibles first!\n");
	}
}

/* This function is responsible for the key hooks
It checks for the "ESC" key or the "WASD" keys. For
the "ESC" key it simply closes the game and for the
"WASD" keys it handles the movement.*/
int	sl_key_hook(int keycode, t_game *game)
{
	static int	moves = 0;

	if (keycode == 65307)
	{
		sl_free_sprites(game);
		sl_end_game(game);
	}
	if ((keycode == 97) || (keycode == 100) || \
	(keycode == 115) || (keycode == 119))
	{
		if (sl_check_collision(game->map, keycode) == 0)
		{
			moves++;
			if (moves == 1)
				ft_printf("You have made %i move.\n", moves);
			else
				ft_printf("You have made %i moves.\n", moves);
		}
		sl_move(game, keycode);
		sl_change_p(game);
		sl_print_map(game);
	}
	return (0);
}
