/*
** EPITECH PROJECT, 2023
** delivery
** File description:
** main
*/

#include "../include/my.h"

int main(int ac, char **av)
{
    matrix *g = malloc(sizeof(matrix) +1);
    char *buffer = map_display();
    char **tab = parsing(tab_c(buffer, '\n'));
    complete_output(g, tab);
}
