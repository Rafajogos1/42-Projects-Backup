/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:54:39 by ramartin          #+#    #+#             */
/*   Updated: 2023/02/09 22:15:47 by rafael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* This function exists due to Norminette's line limit to
reduce "sl_print_map"'s line number */
void	sl_print_map_helper(t_map *map, int *i, int *j)
{
	int	temp;

	if (map->map[*i][*j] == '\n')
	{
		*j = 0;
		temp = *i;
		temp++;
		*i = temp;
	}
}

/* This function goes throught the grid of the ma and draws
the sprites on their correct spots */
void	sl_print_map(void *game, void *game_win, t_map *map, t_spr *sprites)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->map[i][j])
	{
		sl_print_map_helper(map, &i, &j);
		if (map->map[i][j] == 'C')
			mlx_put_image_to_window(game, game_win, sprites->c, \
			(j * 64), (i * 64));
		if (map->map[i][j] == 'E')
			mlx_put_image_to_window(game, game_win, sprites->e, \
			(j * 64), (i * 64));
		if (map->map[i][j] == '0')
			mlx_put_image_to_window(game, game_win, sprites->es, \
			(j * 64), (i * 64));
		if (map->map[i][j] == 'P')
			mlx_put_image_to_window(game, game_win, sprites->p, \
			(j * 64), (i * 64));
		if (map->map[i][j] == '1')
			mlx_put_image_to_window(game, game_win, sprites->w, \
			(j * 64), (i * 64));
		j++;
	}
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
	sl_print_map(game.game, game.win, map, sprites);
	mlx_key_hook(game.win, key_hook, &game);
	mlx_loop(game.game);
	sl_free_map(map);
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
