/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramartin <ramartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:54:42 by ramartin          #+#    #+#             */
/*   Updated: 2023/02/03 19:04:53 by ramartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"
# include <fcntl.h>

typedef struct s_game_map
{
	char	**map;
	int		ccount;
}t_map;

/* so_long */
void	so_long(char *map);

/* Map verification */
int		sl_count_char_2(char **map_grid);
int		sl_count_zeros(char **map_grid);
void	sl_check_next_to(char **map_grid, int *i, int *j);
void	sl_turn_to_minus(char **map_grid);
void	sl_start_coordinates(char **map_grid, int *x, int *y);
void	sl_check_path(char **map_grid);
void	sl_free_grid(char **map_grid);
int		sl_pathfinding(int fd, char *map);
char	**sl_map_grid(int fd, char *map);
int		sl_check_around(char *map);
int		sl_check_rectangle(char *map);
int		sl_valid_char(char *map);
int		sl_count_char(char *map);
char	*sl_get_map(int fd);
int		sl_check_map(char *file);
int		sl_extension(char *file);

#endif