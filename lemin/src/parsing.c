/*
** EPITECH PROJECT, 2023
** delivery
** File description:
** parsing
*/

#include "../include/my.h"

static char *cpy_str(char *dest, char *str)
{
    dest = malloc(sizeof(char) * (my_strlen(str) + 1));
    for (int i = 0; str[i] != '\0'; i++)
        dest[i] = str[i];
    dest[my_strlen(str)] = '\0';
    return dest;
}

static int tab_size(char **tab)
{
    int stock = 0;
    for (int i = 0; tab[i] != NULL; i++){
        if (tab[i][0] == '#')
            continue;
        else
            stock++;
    }
    return stock + 2;
}

static int tun_finder(char *str)
{
    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] == '-')
            return 0;
    }
    return 1;
}

static void parserino(char **tab, char **op, int pass)
{
    for (int i = 0, j = 0; tab[i] != NULL; i++){
        char *str = NULL;
        if (my_comp(tab[i], "##start") == 0)
            op[j] = tab[i], j++, i++;
        if (my_comp(tab[i], "##end") == 0)
            op[j] = tab[i], j++, i++;
        if (tun_finder(tab[i]) == 0 && pass == 1)
            op[j] = cpy_str(op[j], "#tunnels"), j++, pass++;
        if (pass == 1 && tab[i][0] != '#'){
            str = my_strcat(tab_c(tab[i], ' ')[0], tab_c(tab[i], ' ')[1], ' ');
            str = my_strcat(str, tab_c(tab[i], ' ')[2], ' '), op[j] = str, j++;
        }
        if (tun_finder(tab[i]) == 0 && tab[i][0] != '#')
            op[j] = tab_c(tab[i], ' ')[0], j++;
        if (pass == 0 && tab[i][0] != '#'){
            op[j] = cpy_str(op[j], "#number_of_ants"), j++;
            op[j] = tab[i], j++;
            op[j] = cpy_str(op[j], "#rooms"), j++, pass++;
        }
    }
}

char **parsing(char **tab)
{
    int size = tab_size(tab) + 4;
    char **op = malloc(sizeof(char *) * (size + 1));
    op[size] = NULL;
    int pass = 0;

    parserino(tab, op, pass);
    op[size - 1] = cpy_str(op[size - 1], "#moves");
    return op;
}
