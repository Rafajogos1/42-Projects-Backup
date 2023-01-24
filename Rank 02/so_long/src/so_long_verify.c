#include "so_long.h"

int	sl_check_map(char *file)
{
	int		fd;
	char	*s;

	fd = open(file, O_RDONLY);
	s = get_next_line(fd);
	ft_printf("%s", s);
	free(s);
	close (fd);
	return (1);
}

int	sl_extension(char *file)
{
	int		i;
	int		j;
	char	*end;

	end = malloc(sizeof(char *) * 5);
	if (!end)
		return (0);
	i = (ft_strlen(file) - 4);
	while (file[i])
		end[j++] = file[i++];
	if (ft_strncmp(".ber", end, 5) == 0)
	{
		free (end);
		return (1);
	}
	else
	{
		free (end);
		return (0);
	}
}
