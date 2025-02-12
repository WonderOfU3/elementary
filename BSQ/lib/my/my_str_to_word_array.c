/*
** EPITECH PROJECT, 2022
** my_str_to_word_array
** File description:
** task04
*/

#include <stdlib.h>

int is_char(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
        || (c >= '0' && c <= '9'))
        return (1);
    else
        return (0);
}

int count_words(char const *str)
{
    int res = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (is_char(str[i]) == 1 && is_char(str[i - 1]) == 0)
            res++;
    return (res);
}

int my_strlen_changed(char const *str, int i)
{
    while (str[i] != '\0') {
        if (is_char(str[i]) == 0)
            return (i);
        i++;
    }
    return (i);
}

char **my_str_to_word_array(char const *str)
{
    int words = count_words(str);
    char **tab = malloc(sizeof(char *) * words + 1);
    int b = 0;

    for (int i = 0, l = 0, a = 0; i < words; i++) {
        b = 0;
        tab[l] = malloc(sizeof(char) * my_strlen_changed(str, a));
        while (is_char(str[a]) == 0)
            a++;
        for (; str[a] != '\0' && is_char(str[a]) == 1; a++, b++)
            tab[l][b] = str[a];
    l = l + 1;
    }
    return (tab);
}
