/*
** EPITECH PROJECT, 2023
** antman
** File description:
** song
*/

#include <stdlib.h>
#include "antman.h"

int print_ppm_format(char **tab)
{
    int start = 3;
    int i;

    for (i = 0; tab[i] != NULL; i++){
        if (tab[i][0] == '#'){
            start++;
        }
    }
    for (i = 0; i < start; i++){
        my_putstr(tab[i]);
    }
    return start;
}

void compress_ppm(char *str)
{
    char **tab = my_str_to_word_array(str);
    int start = print_ppm_format(tab);
    unsigned char pixel;

    while (tab[start] != NULL){
        pixel = my_getnbr(tab[start]);
        my_putchar(pixel - 128);
        start++;
    }
}

int antman(char const *filepath, char const *filetype)
{
    char *file_content = load_file_in_mem(filepath);

    compress_ppm(file_content);
    return 0;
}
