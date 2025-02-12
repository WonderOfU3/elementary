/*
** EPITECH PROJECT, 2022
** delivery
** File description:
** generate
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "proto.h"

char *generate_map(int size, char *pattern)
{
    int len = my_strlen(pattern);
    char *res = malloc(sizeof(char) * (size * size) + size + 1);
    int a = 0, b = 0;
    for (int i = 0; i < size; i++) {
        for (int c = 0; c < size; a++, b++, c++) {
            if (a == len)
                a = 0;
            res[b] = pattern[a];
        }
        res[b] = '\n';
        b++;
    }
    res[b] = '\0';
    return (res);
}

char *open_read(char *filepath)
{
    struct stat fstat;
    stat(filepath, &fstat);
    int size = fstat.st_size, i = 0, a = 0;
    char *buf = malloc(sizeof(char) * size + 1);
    char *error = my_strdup("error");
    int fd = open(filepath, O_RDONLY);
    if (fd == -1)
        return (error);
    int rd = read(fd, buf, size);
    if (rd <= 0)
        return (error);
    buf[size] = '\0';
    for (; buf[i] != '\n'; i++);
    i++;
    char *buffer = malloc(sizeof(char) * size - i + 1);
    for (; buf[i] != '\0'; i++, a++)
        buffer[a] = buf[i];
    buffer[a] = '\0';
    return (buffer);
}

int count_line(char *buffer)
{
    int res = 1;
    int i = 0;

    for (; buffer[i] != '\0'; i++)
        if (buffer[i] == '\n')
            res++;
    return (res);
}

int count_columns(char *buffer)
{
    int i = 0;
    int res = 0;

    for (; buffer[i] != '\n'; i++, res++);
    res++;
    return (res);
}

int change_numbers(int *tab, int l, int line)
{
    if (tab[l] == 0)
        return (0);
    if (tab[l] == -1)
        return (-1);
    if ((tab[l - line] <= tab[l - line - 1])
    && (tab[l - line] <= tab[l - 1]))
        return (tab[l - line] + 1);
    if ((tab[l - 1] <= tab[l - line - 1])
    && (tab[l - 1] <= tab[l - line]))
        return (tab[l - 1] + 1);
    if ((tab[l - line - 1] <= tab[l - 1])
    && (tab[l - line - 1] <= tab[l - line]))
        return (tab[l - line - 1] + 1);
    return (0);
}
