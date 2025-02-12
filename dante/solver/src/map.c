/*
** EPITECH PROJECT, 2022
** dante
** File description:
** map
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "dante.h"

char *open_read(char *filepath)
{
    struct stat fstat;
    stat(filepath, &fstat);
    int size = fstat.st_size;
    char *buf = malloc(sizeof(char) * size + 1);
    int fd = open(filepath, O_RDONLY);
    if (fd == -1)
        return ("error");
    int rd = read(fd, buf, size);
    if (rd == -1)
        return ("error");
    buf[size] = '\0';
    return (buf);
}
