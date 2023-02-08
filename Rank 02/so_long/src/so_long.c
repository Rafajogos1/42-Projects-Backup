/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:54:39 by ramartin          #+#    #+#             */
/*   Updated: 2023/02/08 22:41:31 by rafael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	so_long(char *file)
{
	int		fd;
	char	*map;
	char	**map_grid;
	int		i;

	fd = open(file, O_RDONLY);
	map = sl_get_map(fd);
	map_grid = sl_map_grid(open(file, O_RDONLY), map);
	i = 0;
	while (map_grid[i])
	{
		ft_printf("%s", map_grid[i]);
		i++;
	}
	ft_printf("\n");
	sl_free_grid(map_grid);
	free(map);
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
