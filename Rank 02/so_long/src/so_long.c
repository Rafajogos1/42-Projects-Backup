#include "so_long.h"

void	so_long(char *map)
{
	if (open(map, O_RDONLY) != -1)
	{
		if (sl_extension(map) == 1)
		{
			sl_check_map(map);
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
