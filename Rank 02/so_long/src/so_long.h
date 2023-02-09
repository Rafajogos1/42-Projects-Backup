/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:54:42 by ramartin          #+#    #+#             */
/*   Updated: 2023/02/09 19:31:46 by rafael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <fcntl.h>

typedef struct s_map
{
	char	**map;
	char	*c_path;
	char	*e_path;
	char	*es_path;
	char	*p_path;
	char	*w_path;
	int		win_w;
	int		win_h;
	int		w;
	int		h;
}t_map;

typedef struct s_spr
{
	void	*c;
	void	*e;
	void	*es;
	void	*p;
	void	*w;
}t_spr;


/* so_long */
void	so_long(char *map);

/* Utillities */
t_spr	*sl_start_sprites(t_map *map, void *game);
void	sl_free_map(t_map *map);
t_map	*sl_start_map(char *file);

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
int		sl_count_lines(char *map);
int		sl_check_around(char *map);
int		sl_check_rectangle(char *map);
int		sl_valid_char(char *map);
int		sl_count_char(char *map);
char	*sl_get_map(int fd);
int		sl_check_map(char *file);
int		sl_extension(char *file);

#endif