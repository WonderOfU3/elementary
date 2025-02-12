/*
** EPITECH PROJECT, 2023
** handle_errors.c
** File description:
** Antman
*/

#include "antman.h"

int handle_errors(char **av)
{
    int i;
    int valid = 0;
    char *options[3] = {"1", "2", "3"};

    for (i = 0; i < 3; i++){
        if (my_strcmp(av[2], options[i]) == 0){
            valid = 1;
            break;
        }
    }
    if (my_strcmp(load_file_in_mem(av[1]), "error") == 0 || valid == 0){
        return 84;
    }
    return 0;
}
