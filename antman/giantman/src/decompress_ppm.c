/*
** EPITECH PROJECT, 2023
** decompress_lyrics.c
** File description:
** Antman
*/

#include "antman.h"
#include <stdio.h>
#include <sys/stat.h>

int print_ppm_format(char *str)
{
    int start = 0;

    while ((str[start] >= ' ' && str[start] <= '~') || str[start] == '\n'){
        my_putchar(str[start]);
        start++;
    }
    return start;
}

void decompress_ppm(char *str, char const *filepath)
{
    int start = print_ppm_format(str);
    char pixel;
    struct stat statbuf;
    int size;

    stat(filepath, &statbuf);
    size = statbuf.st_size;

    while (start < size){
        pixel = str[start];
        my_put_nbr(pixel + 128);
        my_putchar('\n');
        start++;
    }
}

int giantman(char const *filepath, char const *filetype)
{
    char *file_content = load_file_in_mem(filepath);

    if (my_strcmp(filetype, "3") == 0){
        decompress_ppm(file_content, filepath);
    }
    return 0;
}
