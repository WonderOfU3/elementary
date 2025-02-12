/*
** EPITECH PROJECT, 2022
** my_str_to_word_array
** File description:
** task04
*/

#include <stdlib.h>

int is_char(char c)
{
    if (c == '\n')
        return (0);
    else
        return (1);
}

int count_words(char const *str)
{
    int res = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if ((i > 0 && is_char(str[i]) == 1 && is_char(str[i - 1]) == 0)
        || i == 0)
            res++;
    }
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
    char **tab = malloc(sizeof(char *) * words);
    int b = 0, l = 0;

    for (int i = 0, a = 0; i < words; i++) {
        b = 0;
        while (is_char(str[a]) == 0)
            a++;
        tab[l] = malloc(sizeof(char) * my_strlen_changed(str, a) + 1);
        for (; str[a] != '\0' && is_char(str[a]) == 1; a++, b++)
            tab[l][b] = str[a];
        tab[l][b] = '\0';
        l = l + 1;
    }
    return (tab);
}
