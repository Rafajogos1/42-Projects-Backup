#include "so_long.h"

int	sl_valid_char(char c)
{
	if ((c == 'C') || (c == 'E') || (c == 'P') \
	|| (c == '1') || (c == '0') | (c == '\n'))
		return (1);
	else
		return (0);
}

int	sl_count_char(char *map)
{
	int	i;
	int	e;
	int	p;

	i = 0;
	while (map[i++])
	{
		if (sl_valid_char(map[i]) == 0)
			return (0);
		if (map[i] == 'E')
			e++;
		if (map[i] == 'P')
			p++;
	}
	if ((e > 1) || (p > 1))
		return (0);
	else
		return (1);
}

int	sl_count_lines(int fd)
{
	int		i;
	char	*map;

	i = 0;
	while (fd)
	{
		map = get_next_line(fd);
		if (map == NULL)
		{
			free(map);
			break ;
		}
		free(map);
		i++;
	}
	return (i);
}

int	sl_check_map(char *file)
{
	int		fd;
	int		i;
	int		j;
	char	*buf;

	fd = open(file, O_RDONLY);
	i = sl_count_lines(fd);
	fd = open(file, O_RDONLY);
	j = 0;
	while (i-- > 0)
	{
		buf = get_next_line(fd);
		map[j] = buf;
		j++;
		free(buf);
	}
	i = 0;
	ft_printf("%s", map[0]);
	if (sl_count_char(map[i]) == 1)
		ft_printf("A\n");
	free(map);
	close(fd);
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
		free(end);
		return (1);
	}
	else
	{
		free(end);
		return (0);
	}
}
