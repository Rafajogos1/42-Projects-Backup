/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:54:39 by ramartin          #+#    #+#             */
/*   Updated: 2023/02/09 00:07:49 by rafael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	so_long(char *file)
{
	t_map	*map;

	map = sl_start_map(file);
	ft_printf("%s", map->map[0]);
	ft_printf("%s", map->map[1]);
	ft_printf("%s", map->map[2]);
	ft_printf("%s", map->map[3]);
	ft_printf("%s", map->map[4]);
	ft_printf("%s\n", map->map[5]);
	ft_printf("%s\n", map->c_path);
	ft_printf("%s\n", map->e_path);
	ft_printf("%s\n", map->es_path);
	ft_printf("%s\n", map->p_path);
	ft_printf("%s\n", map->w_path);
	sl_free_map(map);
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
