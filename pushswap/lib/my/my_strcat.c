/*
** EPITECH PROJECT, 2022
** my_strcat
** File description:
** task02
*/

#include <stdio.h>
#include <stdlib.h>

int my_strlen(char const *str);

char *my_strcat(char *f_str, char *s_str)
{
    int f_len = my_strlen(f_str);
    int s_len = my_strlen(s_str);
    char *res = malloc(sizeof(char) * (f_len + s_len) + 1);
    int i = 0;
    for (; i < f_len; i++)
        res[i] = f_str[i];
    for (int a = 0; a < s_len; i++, a++)
        res[i] = s_str[a];
    res[i] = '\0';
    return (res);
}
