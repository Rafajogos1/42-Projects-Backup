#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	int		i;
	char	*buf;

	i = 0;
	fd = open("test", O_RDWR);
	if (BUFFER_SIZE <= 0)
	{
		printf("BUFFER_SIZE was set to 0 or lesser value.\n");
		printf("\033[1;36m");
		printf("Check if \"get_next_line\" does not do anything as it should.\n");
		printf("\033[0;37m");
	}
	if (fd < 0)
	{
		printf("No test file detected.\n");
		printf("Please create a file named ");
		printf("\033[0;32m");
		printf("\"test\"");
		printf("\033[0;37m");
		printf(".\n");
	}

	if (BUFFER_SIZE > 0)
	{
		printf("\033[1;37m");
		printf("BUFFER_SIZE = %i: \n\n", BUFFER_SIZE);
	}
	while (fd)
	{
		buf = get_next_line(fd);
		if (buf == NULL)
		{
			free(buf);
			break ;
		}
		else
		{
			printf("\033[1;36m");
			printf("Line %i: ", (i + 1));
			printf("\033[0;37m");
			printf("%s", buf);
		}
		free(buf);
		i++;
	}
	if (BUFFER_SIZE > 0)
	{
		printf("\033[1;37m");
		printf("\n\nRead %i lines.\n", i);
	}
	close(fd);
}