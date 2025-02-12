/*
** EPITECH PROJECT, 2023
** load_file_in_mem.c
** File description:
** Antman
*/

#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>

char *load_file_in_mem(char const *filepath)
{
    struct stat fstat;
    int return_val_stat = stat(filepath, &fstat);
    int size = fstat.st_size;
    char *buf = malloc(sizeof(char) * size + 1);
    int rd;
    int fd = open(filepath, O_RDONLY);

    if (fd == -1 || return_val_stat == -1)
        return ("error");

    rd = read(fd, buf, size);

    if (rd <= 0)
        return ("error");

    buf[size] = '\0';
    return (buf);
}
