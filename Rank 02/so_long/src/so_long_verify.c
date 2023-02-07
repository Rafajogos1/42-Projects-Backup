/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_verify.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramartin <ramartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:54:35 by ramartin          #+#    #+#             */
/*   Updated: 2023/02/07 18:13:21 by ramartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* This function checks if the map is only composed
of the allowed characters */
int	sl_valid_char(char *map)
{
	int		i;
	char	c;

	i = 1;
	while (map[i])
	{
		c = map[i];
		if (!((c == 'C') || (c == 'E') || (c == 'P') || (c == '1') \
		|| (c == '0') || (c == '\n') || (c == '\0')))
		{
			free(map);
			return (0);
		}
		else
			i++;
	}
	return (1);
}

/* This function checks if the characters "C" "E" and "P"
have valid quantities */
int	sl_count_char(char *map)
{
	int	i;
	int	c;
	int	e;
	int	p;

	i = 0;
	c = 0;
	e = 0;
	p = 0;
	while (map[i++])
	{
		if (map[i] == 'C')
			c++;
		if (map[i] == 'E')
			e++;
		if (map[i] == 'P')
			p++;
	}
	if ((c == 0) || (e != 1) || (p != 1))
	{
		free(map);
		return (0);
	}
	else
		return (1);
}

/* This function gets the map from the file */
char	*sl_get_map(int fd)
{
	char	*map;
	char	*buf;

	map = NULL;
	while (fd)
	{
		buf = get_next_line(fd);
		if (buf != NULL)
			map = gnl_ft_strjoin(map, buf);
		else
		{
			free(buf);
			break ;
		}
		free(buf);
	}
	return (map);
}

/* This function checks if the map is according to the rules */
int	sl_check_map(char *file)
{
	int		fd;
	char	*map;

	fd = open(file, O_RDONLY);
	map = sl_get_map(fd);
	if (map == NULL)
		return (0);
	if (sl_valid_char(map) == 0)
		return (0);
	if (sl_count_char(map) == 0)
		return (0);
	if (sl_check_rectangle(map) == 0)
	{
		free(map);
		return (0);
	}
	if (sl_pathfinding(open(file, O_RDONLY), map) == 0)
		return (0);
	free(map);
	close(fd);
	return (1);
}

/* This function checks if the file is ".ber" format */
int	sl_extension(char *file)
{
	int		i;

	i = (ft_strlen(file) - 4);
	if (ft_strncmp(".ber", file + i, 5) == 0)
		return (1);
	else
		return (0);
}
