/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramartin <ramartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:39:55 by rafael            #+#    #+#             */
/*   Updated: 2023/02/10 17:33:21 by ramartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_free_sprites(t_game *game)
{
	mlx_destroy_image(game->game, game->sprites->c);
	mlx_destroy_image(game->game, game->sprites->e);
	mlx_destroy_image(game->game, game->sprites->es);
	mlx_destroy_image(game->game, game->sprites->p);
	mlx_destroy_image(game->game, game->sprites->w);
	free(game->sprites);
}

/* This functionc creates the sprites using the images in "./textures" */
t_spr	*sl_start_sprites(t_map *map, void *game)
{
	t_spr	*sprites;

	sprites = malloc(sizeof(t_spr));
	if (!sprites)
		return (NULL);
	sprites->c = mlx_xpm_file_to_image(game, map->c_path, &map->w, &map->w);
	sprites->e = mlx_xpm_file_to_image(game, map->e_path, &map->w, &map->w);
	sprites->es = mlx_xpm_file_to_image(game, map->es_path, &map->w, &map->w);
	sprites->p = mlx_xpm_file_to_image(game, map->p_path, &map->w, &map->w);
	sprites->w = mlx_xpm_file_to_image(game, map->w_path, &map->w, &map->w);
	if ((!sprites->c) || (!sprites->e) || (!sprites->es) || (!sprites->p) \
	|| (!sprites->w))
		return (NULL);
	return (sprites);
}

/* This function frees the map structure */
void	sl_free_map(t_map *map)
{
	sl_free_grid(map->map);
	free(map);
}

/* This function gets all the necessary data for the game */
t_map	*sl_start_map(char *file)
{	
	int		fd;
	char	*map;
	t_map	*game_map;

	fd = open(file, O_RDONLY);
	map = sl_get_map(fd);
	game_map = malloc(sizeof(t_map));
	if (!game_map)
		return (NULL);
	game_map->c_path = "./textures/C.xpm";
	game_map->e_path = "./textures/E.xpm";
	game_map->es_path = "./textures/0.xpm";
	game_map->p_path = "./textures/P.xpm";
	game_map->w_path = "./textures/1.xpm";
	game_map->win_w = ((ft_strlen(map) - (sl_count_lines(map) - 1)) \
	/ sl_count_lines(map));
	game_map->win_h = sl_count_lines(map);
	game_map->map = sl_map_grid(open(file, O_RDONLY), map);
	free(map);
	close(fd);
	return (game_map);
}
