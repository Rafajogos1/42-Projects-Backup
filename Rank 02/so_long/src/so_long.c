/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramartin <ramartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:54:39 by ramartin          #+#    #+#             */
/*   Updated: 2023/02/07 18:39:50 by ramartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	so_long(char *file)
{
	int		fd;
	char	*map;
	char	**game_map;

	fd = open(file, O_RDONLY);
	map = sl_get_map(fd);
	game_map = sl_map_grid(open(file, O_RDONLY), map);
	ft_printf("%s\n", game_map[0]);
	close(fd);
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
