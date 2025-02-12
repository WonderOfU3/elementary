/*
** EPITECH PROJECT, 2023
** antman
** File description:
** antman
*/

#ifndef ANTMAN_H_
    #define ANTMAN_H_

char *load_file_in_mem(char const *filepath);

int my_strcmp(char const *s1, char const *s2);

int my_putstr(char const *str);

void my_putchar(char c);

int my_put_nbr(int nb);

int my_strlen(char const *str);

int handle_errors(char **av);

int antman(char const *filepath, char const *filetype);

int giantman(char const *filepath, char const *filetype);

void decompress_ppm(char *str, char const *filepath);

char **my_str_to_word_array(char const *str);

int put_words_in_array(int *word_start, int j, char const *str, char **words);

int find_word_end(char const *str, int word_start);

char *retrieve_word(char *dest, char const *str, int word_start, int word_end);

int find_word_end(char const *str, int word_start);

int my_getnbr(char const *str);

#endif
