/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramartin <ramartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:54:39 by ramartin          #+#    #+#             */
/*   Updated: 2023/01/31 18:33:15 by ramartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	so_long(char *map)
{
	if (open(map, O_RDONLY) != -1)
	{
		if (sl_extension(map) == 1)
		{
			if (sl_check_map(map) == 1)
				ft_printf("Yes\n");
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

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		so_long(av[1]);
	}
}
