/*
** EPITECH PROJECT, 2023
** dante
** File description:
** solve
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dante.h"

void find_path(char **tab, pos_t *p)
{
    int pass = 0;
    if (p->c < p->max_c && tab[p->l][p->c + 1] == '*') {
        p->c++;
        pass = 1;
    }
    if (p->l < p->max_l && tab[p->l + 1][p->c] == '*' && pass == 0) {
        p->l++;
        pass = 1;
    }
    if (p->l > 0 && tab[p->l - 1][p->c] == '*' && pass == 0) {
        p->l--;
        pass = 1;
    }
    if (p->c > 0 && tab[p->l][p->c - 1] == '*' && pass == 0) {
        p->c--;
        pass = 1;
    }
    tab[p->l][p->c] = 'm';
}

int check_blocked(char **tab, pos_t *p)
{
    int check = 0;
    if (p->c < p->max_c)
        if (tab[p->l][p->c + 1] == 'X' || tab[p->l][p->c + 1] == 'm'
        || tab[p->l][p->c + 1] == 'a')
            check++;
    if (p->c > 0)
        if (tab[p->l][p->c - 1] == 'X' || tab[p->l][p->c - 1] == 'm'
        || tab[p->l][p->c - 1] == 'a')
            check++;
    if (p->l < p->max_l)
        if (tab[p->l + 1][p->c] == 'X' || tab[p->l + 1][p->c] == 'm'
        || tab[p->l + 1][p->c] == 'a')
            check++;
    if (p->l > 0)
        if (tab[p->l - 1][p->c] == 'X' || tab[p->l - 1][p->c] == 'm'
        || tab[p->l - 1][p->c] == 'a')
            check++;
    (p->c == 0 || p->c == p->max_c) ? check++ : 0;
    (p->l == 0 || p->l == p->max_l) ? check++ : 0;
    return (check);
}

void get_unblocked(char **tab, pos_t *p)
{
    for (int pass = 0; check_blocked(tab, p) == 4 ||
    (tab[1][0] == 'a' && tab[0][1] == 'a'); ) {
        tab[p->l][p->c] = 'a';
        if (tab[p->l][p->c - 1] == 'm') {
            p->c--;
            pass = 1;
        }
        if (tab[p->l - 1][p->c] == 'm' && pass == 0) {
            p->l--;
            pass = 1;
        }
        if (tab[p->l + 1][p->c] == 'm' && pass == 0) {
            p->l++;
            pass = 1;
        }
        if (tab[p->l][p->c + 1] == 'm' && pass == 0) {
            p->c++;
            pass = 1;
        }
        pass = 0;
    }
}

char **solve_maze(char **tab, char *str, pos_t *p)
{
    int col = my_strlen(tab[0]) - 1;
    int line = count_words(str) - 1;
    p->l = 0;
    p->c = 0;
    p->max_l = line;
    p->max_c = col;
    tab[0][0] = 'm';
    while (tab[line - 1][col] != 'm' && tab[line][col - 1] != 'm') {
        find_path(tab, p);
        if (check_blocked(tab, p) == 4)
            get_unblocked(tab, p);
        if (tab[1][0] == 'a' && tab[0][1] == 'a')
            break;
        write(1, "\n\n", 2);
        print_map(tab, str);
    }
    tab[line][col] = 'm';
    return (tab);
}

char **get_solved_map(char **tab, char *str)
{
    for (int i = 0, a = 0; i < count_words(str); a++) {
        if (tab[i][a] == 'm')
            tab[i][a] = 'o';
        if (tab[i][a] == 'a')
            tab[i][a] = '*';
        if (tab[i][a] == '\0') {
            i++;
            a = -1;
        }
    }
    return (tab);
}
