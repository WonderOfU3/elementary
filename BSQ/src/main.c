/*
** EPITECH PROJECT, 2022
** delivery
** File description:
** main
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include "proto.h"

void char_to_int(char *str, int *tab, int i)
{
    if (str[i] == '.')
        tab[i] = 1;
    if (str[i] == 'o')
        tab[i] = 0;
    if (str[i] == '\n')
        tab[i] = -1;
}

void put_values(int *tab, char *str, struct bsq *bsq)
{
    int res = 0;
    bsq->number = 0;
    int line = count_columns(str);
    int i = 0;
    for (; str[i] != '\0'; i++) {
        char_to_int(str, tab, i);
        if (i >= line + 1 && tab[i - 1] != -1 && tab[i] != -1)
            tab[i] = change_numbers(tab, i, line);
        if (res < tab[i]) {
            res = tab[i];
            bsq->number = res;
            bsq->pos = i;
        }
    }
    tab[i] = -2;
}

int *itoa(struct bsq *bsq, char *str)
{
    int col = count_columns(str);
    int line = count_line(str);
    int *tab = malloc(sizeof(int) * (col * line) + 1);
    put_values(tab, str, bsq);
    return (tab);
}

char *print_final(struct bsq *bsq, char *str)
{
    int *tab = itoa(bsq, str);
    int len = count_columns(str);
    int b = 0, p = bsq->pos;
    for (int a = 0; b < bsq->number * bsq->number; b++, p--, a++) {
        if (a == bsq->number) {
            p -= len - bsq->number;
            a = 0;
        }
        str[p] = 'x';
    }
    free(tab);
    return (str);
}

int main(int ac, char **av)
{
    struct bsq *bsq = malloc(sizeof(struct bsq));
    char *str, *final;
    if (ac < 2 || ac > 3 || (my_strcmp(open_read(av[1]), "error") == 0 &&
    ((av[1][0] < '1' || av[1][0] > '9') || my_strlen(av[2]) == 0)))
        return (84);
    if (my_strcmp(open_read(av[1]), "error") != 0) {
        str = open_read(av[1]);
        final = print_final(bsq, str);
        int size = my_strlen(final);
        write(1, final, size);
    } else {
        str = generate_map(my_getnbr(av[1]), av[2]);
        final = print_final(bsq, str);
        int size = my_strlen(final);
        write(1, final, size);
    }
    free(final);
}
