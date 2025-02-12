/*
** EPITECH PROJECT, 2023
** antman
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "dante.h"

void print_map(char **tab, char *str)
{
    for (int i = 0; i < count_words(str); i++) {
        write(1, tab[i], strlen(tab[i]));
        if (i != count_words(str) - 1)
            write(1, "\n", 1);
    }
}

int main(int ac, char **av)
{
    int x, y;
    char *str, **tab;
    pos_t *p = malloc(sizeof(pos_t));
    if (ac != 2 || strcmp("error", open_read(av[1])) == 0)
        return (84);
    else {
        str = open_read(av[1]);
        tab = my_str_to_word_array(str);
        y = count_words(str) - 1;
        x = strlen(tab[0]) - 1;
        solve_maze(tab, str, p);
        get_solved_map(tab, str);
        if (tab[y][x - 1] != 'o' && tab[y - 1][x] != 'o')
            return (84);
        print_map(tab, str);
        for (int i = 0; i < count_words(str); i++)
            free(tab[i]);
        free(str);
    }
    free(p);
    return 0;
}
