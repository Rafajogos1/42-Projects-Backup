#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	int		fd2;
	int		i;
	int		j;

	i = 0;
	j = 1;
	fd = open("test", O_RDWR);
	fd2 = open("test", O_RDWR);
	if (BUFFER_SIZE <= 0)
	{
		printf("\033[1;31m");
		printf("ERROR\n");
		printf("\033[0;37m");
		printf("BUFFER_SIZE must be a positive value.\n");
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
	while (get_next_line(fd))
		i++;
	if (BUFFER_SIZE > 0 && !(fd < 0))
	{
		printf("\033[1;37m");
		printf("BUFFER_SIZE = %i: \n\n", BUFFER_SIZE);
	}
	while (i != 0)
	{
		printf("\033[1;36m");
		printf("Line %i: ", j);
		printf("\033[0;37m");
		printf("%s", get_next_line(fd2));
		j++;
		i--;
	}
	if (BUFFER_SIZE > 0 && !(fd < 0))
	{
		printf("\033[1;37m");
		printf("\n\nRead %i lines.\n", (j - 1));
	}
	close(fd);
}