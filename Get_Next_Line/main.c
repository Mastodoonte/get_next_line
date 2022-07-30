#include <stdio.h>
#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main(int ac, char **av)
{
    if (ac != 2)
    {
        printf("errror\n");
        exit(1);
    }
    int fd = open(av[1],  O_RDONLY);
    char *line;

    while (get_next_line(fd, &line) > 0)
    {
        printf("value = %s\n", line);
        free(line);
    }
}