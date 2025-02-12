/*
** EPITECH PROJECT, 2023
** delivery
** File description:
** algo
*/

#include "../include/my.h"

int my_put_nbr(int nbr)
{
    char nb = nbr + '0';
    char min = '-';

    if (nbr >= 0 && nbr < 10)
        write(1, &nb, 1);
    else if (nbr < 0){
        write(1, &min, 1);
        my_put_nbr(nbr * (-1));
    }else{
        my_put_nbr(nbr / 10);
        my_put_nbr(nbr % 10);
    }
}

static void groovie(matrix *g, char *path, int k, int pass)
{
    if (pass > 0)
        write(1, " ", 1);
    write(1, "P", 1);
    my_put_nbr(g->fourmis - k);
    write(1, "-", 1);
    write(1, path, my_strlen(path));
}

char *pathing(matrix *g, char *room, char **tun, char **path)
{
    for (int k = 0; k != g->nb_tunnel; k++){
        if (my_comp(room, tab_c(tun[k], '-')[0]) == 0){
            room = tab_c(tun[k], '-')[1];
            tun[k] = "caca";
            break;
        }
        if (my_comp(room, tab_c(tun[k], '-')[1]) == 0){
            room = tab_c(tun[k], '-')[0];
            tun[k] = "caca";
            break;
        }
    }
    g->mouv++;
    path[g->mouv] = room;
    return room;
}

void print_moves(matrix *g, char **path)
{
    int *four = malloc(sizeof(int) * (g->mouv + 1));
    four[0] = g->fourmis;
    for (int i = 1; i != g->mouv + 1; i++)
        four[i] = 0;
    int i = 1, mala = 1, pass = 0;
    while (four[g->mouv] != g->fourmis){
        for (int j = g->mouv - 1; j != 0; j--)
            (four[j] > 0) ? (four[j] -= 1, four[j + 1] += 1) : (0);
        if (four[0] > 0)
            four[0] += - 1, four[1] += 1;
        for (int j = g->mouv, k = g->fourmis - mala; j != 0; j--){
            (four[j] > 0) ? (groovie(g, path[j], k, pass),
            (j == g->mouv) ? (mala++) : (0),
            k--, pass++) : (0);
        }
        write(1, "\n", 1);
        pass = 0;
    }
}

void complete_output(matrix *g, char **tab)
{
    printer(tab);
    values01(g, tab);
    values02(g, tab);
    int **mat = matrice(g);
    char *room = g->room[0];
    char **tun = g->tunnel;

    char **path = malloc(sizeof(char *) * 1000);
    path[0] = room;

    for (int i = 0; i != g->nb_room; i++){
        for (int j = 0; j != g->nb_room; j++){
            (my_comp(room, g->room[g->nb_room - 1]) == 0) ?
            (j = g->nb_room - 1, i = g->nb_room - 1) : (0);
            (mat[i][j] == 1) ? (room = pathing(g, room, tun, path)) : (0);
        }
    }

    print_moves(g, path);
}
