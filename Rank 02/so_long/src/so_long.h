/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramartin <ramartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:54:42 by ramartin          #+#    #+#             */
/*   Updated: 2023/01/30 18:28:01 by ramartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include <fcntl.h>

typedef struct s_game_map
{
	char	*map;
	int		ccount;
}t_map;

/* so_long */
void	so_long(char *map);

/* Map verification */
int		sl_check_around(char *map);
int		sl_check_rectangle(char *map);
int		sl_valid_char(char *map);
int		sl_count_char(char *map);
char	*sl_get_map(int fd);
int		sl_check_map(char *file);
int		sl_extension(char *file);

#endif