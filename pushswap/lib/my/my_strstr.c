/*
** EPITECH PROJECT, 2022
** m_strstr
** File description:
** task05
*/

#include <stddef.h>

int my_strlen(char const *str);

char *my_strstr(char *str, char const *to_find)
{
    int len = my_strlen(to_find);

    for (int i = 0, a = 0; str[i] != '\0'; i++) {
        if (str[i] == to_find[a])
            a++;
        else
            a = 0;
        if (a == len)
            return (to_find);
    }
    return (NULL);
}
