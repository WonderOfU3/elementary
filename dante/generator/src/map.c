/*
** EPITECH PROJECT, 2023
** dante
** File description:
** map
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "dante.h"

void print_maze(char **tab, int y)
{
    for (int i = 0; i < y; i++) {
        write(1, tab[i], strlen(tab[i]));
        if (i != y - 1)
            write(1, "\n", 1);
    }
}

void generate_walls(char **tab, int l, int b)
{
    if (l % 2 == 0)
        tab[l][b] = '*';
    else
        tab[l][b] = 'X';
    if (l == 0 && b == 0)
        tab[l][b] = '*';
}

char **generate_full_maze(int x, int y)
{
    char **tab = malloc(sizeof(char *) * y);
    int b = 0, l = 0;

    for (int i = 0; i < y; i++) {
        b = 0;
        tab[l] = malloc(sizeof(char) * x + 1);
        for (; b < x; b++)
            generate_walls(tab, l, b);
        tab[l][b] = '\0';
        l = l + 1;
    }
    tab[y - 1][x - 1] = '*';
    return (tab);
}

char **perfect_maze(char **tab, int x, int y)
{
    int random;
    for (int i = 1; i < y; i += 2) {
        for (int a = 0; a < x; a++) {
            random = rand() % x;
            tab[i][random + 2] != '*' && tab[i][random - 2] != '*' ?
            tab[i][random] = '*' : 0;
        }
    }
    return (tab);
}

char **imperfect_maze(char **tab, int x, int y)
{
    int random;
    for (int i = 1; i < y; i += 2) {
        for (int a = 0; a < x; a++) {
            random = rand() % (x - 2);
            tab[i][random + 2] != '*' && tab[i][random - 2] != '*' ?
            tab[i][random] = '*', tab[i][random + 2] = '*' : 0;
        }
    }
    return (tab);
}
