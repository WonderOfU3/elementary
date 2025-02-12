/*
** EPITECH PROJECT, 2022
** my_str_to_word_array.c
** File description:
** Day 08 - Task 04 - my_str_to_word_array.c
*/

#include <stdlib.h>
#include "antman.h"

int find_word_end(char const *str, int word_start)
{
    int word_end;
    int i = 0;
    while (str[word_start + i] != '\n'){
            i += 1;
    }
    word_end = word_start + i;
    return word_end;
}

char *retrieve_word(char *dest, char const *str, int word_start, int word_end)
{
    int word_len = (word_end - word_start) + 1;
    int i = 0;
    dest = malloc(word_len * sizeof(char));
    while ((word_start + i) <= word_end){
        dest[i] = str[word_start + i];
        i += 1;
    }
    dest[i] = '\0';
    return dest;
}

int array_len(char **array)
{
    int len = 0;
    while (array[len] != NULL){
        len += 1;
    }
    return len;
}

int words_nb(char const *str)
{
    int word_end;
    int nb = 0;
    int i = 0;
    while (str[i] != '\0'){
        if (str[i] != '\n'){
            word_end = find_word_end(str, i);
            nb += 1;
            i = word_end;
        } else{
            i += 1;
        }
    }
    return nb;
}

char **my_str_to_word_array(char const *str)
{
    char **words;
    int word_end;
    int word_len = 0;
    int j = 0;

    words = malloc((words_nb(str) + 2) * sizeof(char *));
    for (int i = 0; str[i] != '\0';){
        if (str[i] != '\n'){
            word_end = find_word_end(str, i);
            word_len = (word_end - i) + 1;
            words[j] = malloc((word_len + 1) * sizeof(char));
            words[j] = retrieve_word(words[j], str, i, word_end);
            j += 1;
            i = word_end;
        } else
            i += 1;
    }
    words[j] = NULL;
    return words;
}
