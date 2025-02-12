/*
** EPITECH PROJECT, 2023
** delivery
** File description:
** fonctions
*/

#include "my.h"

void printer(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++){
        write(1, tab[i], my_strlen(tab[i]));
        write(1, "\n", 1);
    }
}

int my_strlen(char const * str)
{
    int i = 0;
    if (str == NULL)
        return i;
    while (str[i] != '\0'){
        i++;
    }
    return i;
}

int my_comp(char *str, char *comp)
{
    int j = my_strlen(str), k = my_strlen(comp), stock = 0;
    if (j != k)
        return 84;
    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] == comp[i])
            stock += 1;
    }
    if (stock == k)
        return 0;
    else
        return 84;
}

char *my_strcat(char *dest, char *src, char c)
{
    int size1 = my_strlen(dest), size2 = my_strlen(src), j = 0;
    char *result = malloc(sizeof(char) * size1 + size2 + 2);
    result[size1 + size2 + 1] = '\0';
    for (int i = 0; i != size1; i++){
        result[i] = dest[i];
    }
    result[size1] = c;
    for (int i = size1 + 1; i != size1 + size2 + 1; i++){
        result[i] = src[j];
        j++;
    }
    result[size1 + size2 + 1] = '\0';
    return result;
}

int my_atoi(char *str)
{
    int nb = 0;
    int stock = 0, j = 1, div = 10;

    if (str[0] == '-'){
        j = j * -1;
        *str++;
    }
    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] == '.'){
            stock = i;
            i++;
        }
        nb = nb * 10 + str[i] - '0';
    }
    return (nb * j);
}
