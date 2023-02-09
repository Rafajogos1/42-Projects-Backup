/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:39:55 by rafael            #+#    #+#             */
/*   Updated: 2023/02/09 01:16:19 by rafael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	int		n;
	char	*map;
	t_map	*game_map;

	fd = open(file, O_RDONLY);
	map = sl_get_map(fd);
	n = (85 + sl_count_lines(map));
	game_map = malloc(sizeof(t_map *) * n);
	if (!game_map)
		return (NULL);
	game_map->c_path = "./textures/C.xpm";
	game_map->e_path = "./textures/E.xpm";
	game_map->es_path = "./textures/0.xpm";
	game_map->p_path = "./textures/P.xpm";
	game_map->w_path = "./textures/1.xpm";
	game_map->map = sl_map_grid(open(file, O_RDONLY), map);
	free(map);
	close(fd);
	return (game_map);
}
