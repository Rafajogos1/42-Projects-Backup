#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
{
    int fd;

    fd = open("test", O_RDONLY);
    get_next_line(fd);
    printf("%s", get_next_line(fd));
    close(fd);
}