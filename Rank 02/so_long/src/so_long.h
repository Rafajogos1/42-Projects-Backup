/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramartin <ramartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:54:42 by ramartin          #+#    #+#             */
/*   Updated: 2023/02/10 17:50:21 by ramartin         ###   ########.fr       */
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

typedef struct s_game{
	void	*game;
	void	*win;
	t_map	*map;
	t_spr	*sprites;
}t_game;

/* so_long */
int		sl_end_game(t_game *game);
void	sl_print_map_helper(t_game *game, int *i, int *j);
void	sl_print_map(t_game *game);
void	so_long(char *map);

/* Hooks */
void	sl_find_p(t_map *map, int *x, int *y);
int		sl_check_collision(t_map *map, int keycode);
void	sl_move_horizontal(t_game *game, int keycode, int *x, int *y);
void	sl_move_vertical(t_game *game, int keycode, int *x, int *y);
void	sl_move(t_game *game, int keycode);
int		key_hook(int keycode, t_game *game);

/* Utillities */
void	sl_free_sprites(t_game *game);
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