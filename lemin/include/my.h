/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** project bsq
*/

#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <ncurses.h>

#ifndef MY_H_
    #define MY_H_

    typedef struct matrix{
        int fourmis;
        int mouv;
        int nb_room;
        int nb_tunnel;
        char **room;
        char **tunnel;
    }matrix;

    char **parsing(char **tab);

    //fonctions :

    void printer(char **tab);
    int my_strlen(char const * str);
    int my_comp(char *str, char *comp);
    char *my_strcat(char *dest, char *src, char c);
    int my_atoi(char *str);

    //double_tab :

    char *map_display(void);
    int verif(char c, char comp);
    int count_w(char *str,char comp);
    int *count_s(char *str, char comp);
    char **tab_c(char *str, char c);

    //matrix :

    void values01(matrix *g, char **tab);
    void values02(matrix *g, char **tab);
    int **matrice(matrix *g);

    //algo :

    char *pathing(matrix *g, char *room, char **tun, char **path);
    void print_moves(matrix *g, char **path);
    void complete_output(matrix *g, char **tab);

#endif /* !MY_H_ */
