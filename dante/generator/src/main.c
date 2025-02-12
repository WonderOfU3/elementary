/*
** EPITECH PROJECT, 2023
** antman
** File description:
** main
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "dante.h"

int error_handling(int ac, char **av)
{
    if (ac == 4 && strcmp(av[3], "perfect") == 0)
        return (0);
    if (ac != 3)
        return (84);
    for (int i = 1, a = 0; i < ac; a++) {
        if (av[i][a] < '0' || av[i][a] > '9')
            return (84);
        if (av[i][a + 1] == '\0') {
            i++;
            a = -1;
        }
    }
    if (atoi(av[1]) == 0 || atoi(av[2]) == 0)
        return (84);
    return (0);
}

int main(int ac, char **av)
{
    char **tab;
    srand(time(NULL));
    if (error_handling(ac, av) == 84)
        return (84);
    else {
        tab = generate_full_maze(atoi(av[1]), atoi(av[2]));
        if (ac == 3)
            tab = imperfect_maze(tab, atoi(av[1]), atoi(av[2]));
        else
            tab = perfect_maze(tab, atoi(av[1]), atoi(av[2]));
        print_maze(tab, atoi(av[2]));
        for (int i = 0; i < atoi(av[2]); i++)
            free(tab[i]);
    }
}
