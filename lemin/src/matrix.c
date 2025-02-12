/*
** EPITECH PROJECT, 2023
** delivery
** File description:
** matrix
*/

#include "../include/my.h"

void values01(matrix *g, char **tab)
{
    g->nb_room = 0, g->nb_tunnel = 0, g->mouv = 0;
    for (int i = 0, pass = 0; tab[i] != NULL; i++){
        if (pass > 0 && tab[i][0] != '#' && tab_c(tab[i], '-')[1] == NULL)
            g->nb_room++;
        if (pass > 0 && tab[i][0] != '#' && tab_c(tab[i], '-')[1] != NULL)
            g->nb_tunnel++;
        if (pass == 0 && tab[i][0] != '#'){
            g->fourmis = my_atoi(tab[i]);
            pass++;
        }
    }
}

void values02(matrix *g, char **tab)
{
    g->room = malloc(sizeof(char *) * (g->nb_room + 1));
    g->tunnel = malloc(sizeof(char *) * (g->nb_tunnel + 1));
    g->room[g->nb_room] = NULL, g->tunnel[g->nb_tunnel] = NULL;

    for (int i = 0, j = 1, k = 0, pass = 0; tab[i] != NULL; i++){
        if (pass > 0 && my_comp(tab[i - 1], "##start") == 0){
            g->room[0] = tab_c(tab[i], ' ')[0], i++;
        }
        if (pass > 0 && my_comp(tab[i - 1], "##end") == 0){
            g->room[g->nb_room - 1] = tab_c(tab[i], ' ')[0], i++;
        }
        if (pass > 0 && tab[i][0] != '#' && tab_c(tab[i], '-')[1] == NULL){
            g->room[j] = tab_c(tab[i], ' ')[0], j++;
        }
        if (pass > 0 && tab[i][0] != '#' && tab_c(tab[i], '-')[1] != NULL){
            g->tunnel[k] = tab[i], k++;
        }
        if (pass == 0 && tab[i][0] != '#')
            pass++;
    }
}

static void fill_matrix(matrix *g, int **tab, int i, int j)
{
    int k = 0;

    while (k != g->nb_tunnel){
        if ((my_comp(g->room[i], tab_c(g->tunnel[k], '-')[0]) == 0
        || my_comp(g->room[i], tab_c(g->tunnel[k], '-')[1]) == 0) &&
        (my_comp(g->room[j], tab_c(g->tunnel[k], '-')[0]) == 0
        || my_comp(g->room[j], tab_c(g->tunnel[k], '-')[1]) == 0)){
            tab[i][j] = 1;
            break;
        }
        k++;
    }
    if (k == g->nb_tunnel)
        tab[i][j] = 0;
    if (my_comp(g->room[i], g->room[j]) == 0)
        tab[i][j] = 0;
}

int **matrice(matrix *g)
{
    int **tab = malloc(sizeof(int *) * (g->nb_room + 1));
    tab[g->nb_room] = NULL;

    for (int i = 0; i != g->nb_room; i++){
        tab[i] = malloc(sizeof(int) * (g->nb_room + 1));
        for (int j = 0; j != g->nb_room; j++){
            fill_matrix(g, tab, i, j);
        }
    }
    return tab;
}
