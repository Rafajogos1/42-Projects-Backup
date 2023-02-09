/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:39:55 by rafael            #+#    #+#             */
/*   Updated: 2023/02/09 00:08:22 by rafael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_free_map(t_map *map)
{
	sl_free_grid(map->map);
	free(map);
}

t_map	*sl_start_map(char *file)
{	
	int		fd;
	char	*map;
	t_map	*game_map;

	fd = open(file, O_RDONLY);
	map = sl_get_map(fd);
	game_map = malloc(sizeof(t_map *) * (4 * (ft_strlen("./textures/teapot.xpm"))));
	if (!game_map)
		return (NULL);
	game_map->c_path = "./textures/teapot.xpm";
	game_map->e_path = "./textures/teapot.xpm";
	game_map->es_path = "./textures/teapot.xpm";
	game_map->p_path = "./textures/teapot.xpm";
	game_map->w_path = "./textures/teapot.xpm";
	game_map->map = sl_map_grid(open(file, O_RDONLY), map);
	free(map);
	close(fd);
	return (game_map);
}
