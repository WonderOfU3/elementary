/*
** EPITECH PROJECT, 2023
** delivery
** File description:
** my_strword_array
*/

#include "../include/my.h"

char *map_display(void)
{
    char *buffer = malloc(sizeof(char) * 30000);
    int file = read(0, buffer, 29999);
    if (file == -1)
        return (NULL);
    buffer[file] = '\0';
    return buffer;
}

int verif(char c, char comp)
{
    if (c == comp || c == '\0')
        return 0;
    return 1;
}

int count_w(char *str, char comp)
{
    int stock = 0;
    for (int i = 0; str[i] != '\0'; i++){
        if (verif(str[i], comp) == 1 && verif(str[i + 1], comp) == 0)
            stock += 1;
    }
    return stock;
}

int *count_s(char *str, char comp)
{
    int *tab = malloc(sizeof(int) * count_w(str, comp));
    int j = 0, stock = 0;
    for (int i = 0; i < count_w(str, comp);){
        while (verif(str[j], comp) == 0)
            j += 1;
        while (verif(str[j], comp) == 1){
            stock += 1;
            j += 1;
        }
        if (verif(str[j], comp) == 0){
            tab[i] = stock;
            stock = 0;
            i += 1;
        }
    }
    return tab;
}

char **tab_c(char *str, char c)
{
    char **tab = malloc(sizeof(char *) * (count_w(str, c) + 1));
    int *tab_i = count_s(str, c);
    int j = 0, k = 0;
    for (int i = 0; i != count_w(str, c); i++){
        tab[i] = malloc(sizeof(char) * tab_i[i] + 1);
        tab[i][tab_i[i]] = '\0';
        while (verif(str[k], c) == 0){
            k += 1;
        }
        for (; j < tab_i[i];){
            tab[i][j] = str[k];
            j += 1;
            k += 1;
        }
        j = 0;
    }
    tab[count_w(str, c)] = NULL;
    return tab;
}
