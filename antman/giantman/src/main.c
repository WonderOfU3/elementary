/*
** EPITECH PROJECT, 2023
** antman
** File description:
** main
*/

#include <fcntl.h>
#include <unistd.h>
#include <antman.h>

int main(int ac, char **av)
{
    if (ac == 3 && handle_errors(av) == 0) {
        giantman(av[1], av[2]);
        return 0;
    }
    return 84;
}
