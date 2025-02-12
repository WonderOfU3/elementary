/*
** EPITECH PROJECT, 2022
** put_words_in_array.c
** File description:
** put_words_in_array.c
*/

#include <stdlib.h>
#include "antman.h"

int put_words_in_array(int *word_start, int j, char const *str, char **words)
{
    int word_end = find_word_end(str, *word_start);
    int word_len = (word_end - *word_start) + 1;
    words[j] = malloc((word_len + 1) * sizeof(char));
    words[j] = retrieve_word(words[j], str, *word_start, word_end);
    return word_end;
}
