/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramartin <ramartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:54:39 by ramartin          #+#    #+#             */
/*   Updated: 2023/02/10 17:35:09 by ramartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* This function is responsible for closing the game */
int	sl_end_game(t_game *game)
{
	mlx_clear_window(game->game, game->win);
	mlx_destroy_window(game->game, game->win);
	mlx_destroy_display(game->game);
	sl_free_map(game->map);
	free(game->game);
	exit(0);
}

/* This function exists due to Norminette's line limit to
reduce "sl_print_map"'s line number */
void	sl_print_map_helper(t_game *game, int *i, int *j)
{
	if (game->map->map[*i][*j] == 'C')
		mlx_put_image_to_window(game->game, game->win, game->sprites->c, \
		(*j * 64), (*i * 64));
	if (game->map->map[*i][*j] == 'E')
		mlx_put_image_to_window(game->game, game->win, game->sprites->e, \
		(*j * 64), (*i * 64));
	if (game->map->map[*i][*j] == '0')
		mlx_put_image_to_window(game->game, game->win, game->sprites->es, \
		(*j * 64), (*i * 64));
	if (game->map->map[*i][*j] == 'P')
		mlx_put_image_to_window(game->game, game->win, game->sprites->p, \
		(*j * 64), (*i * 64));
	if (game->map->map[*i][*j] == '1')
		mlx_put_image_to_window(game->game, game->win, game->sprites->w, \
		(*j * 64), (*i * 64));
}

/* This function goes throught the grid of the map and draws
the sprites on their correct spots */
void	sl_print_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map->map[i][j])
	{
		if (game->map->map[i][j] == '\n')
		{
			j = 0;
			i++;
		}
		sl_print_map_helper(game, &i, &j);
		j++;
	}
	sl_free_sprites(game);
}

void	so_long(char *file)
{
	t_map	*map;
	t_spr	*sprites;
	t_game	game;

	map = sl_start_map(file);
	game.game = mlx_init();
	sprites = sl_start_sprites(map, game.game);
	game.win = mlx_new_window(game.game, (map->win_w * 64), \
	(map->win_h * 64), "so_long");
	game.map = map;
	game.sprites = sprites;
	sl_print_map(&game);
	mlx_key_hook(game.win, key_hook, &game);
	mlx_hook(game.win, 17, 0, &sl_end_game, &game);
	mlx_loop(game.game);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		if (open(av[1], O_RDONLY) != -1)
		{
			if (sl_extension(av[1]) == 1)
			{
				if (sl_check_map(av[1]) == 1)
					so_long(av[1]);
				else
					ft_printf("Error\nThe recieved map is not valid.\n");
			}
			else
				ft_printf("Error\nFile not in \".ber\" format.\n");
		}
		else
			ft_printf("Error\nFile not found.\n");
		close(1);
	}
}
