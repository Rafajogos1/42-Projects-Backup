/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_hooks_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:48:13 by ramartin          #+#    #+#             */
/*   Updated: 2023/02/19 23:01:28 by rafael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* This function changes the player's sprite to the correct
one, checking if it is on top of the exit or not. */
void	sl_change_p(t_game *game)
{
	mlx_destroy_image(game->game, game->sprites->p);
	if (sl_find_e(game->map) == 0)
	{
		game->sprites->p = mlx_xpm_file_to_image(game->game, \
		game->map->p2_path, &game->map->w, &game->map->w);
	}
	else
	{
		game->sprites->p = mlx_xpm_file_to_image(game->game, \
		game->map->p_path, &game->map->w, &game->map->w);
	}
}

/* This function frees the sprites and then, closes the game. */
int	sl_close_x(t_game *game)
{
	sl_free_sprites(game);
	sl_end_game(game);
	return (0);
}

/* This function checks for the character "C". */
int	sl_find_c(t_map *map)
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
		if (map->map[i][j] == 'C')
			return (1);
		j++;
	}
	return (0);
}

/* This function checks for the character "E". */
int	sl_find_e(t_map *map)
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
		if (map->map[i][j] == 'E')
			return (1);
		j++;
	}
	return (0);
}

/* This function checks for the character "P" and
saves its coordinates. */
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
