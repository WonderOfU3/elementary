/*
** EPITECH PROJECT, 2022
** delivery
** File description:
** proto
*/

#ifndef PROTO_H_
    #define PROTO_H_

typedef struct bsq {
    int number;
    int pos;
    int size;
} bsq;

void my_putchar(char c);

char *open_read(char *filepath);

int count_line(char *buffer);

int count_columns(char *buffer);

int my_putstr(char const *str);

int my_strcmp(char const *s1, char const *s2);

int my_strlen(char const *str);

char *my_strdup(char const *src);

char *generate_map(int size, char *pattern);

int my_getnbr(char const *str);

int change_numbers(int *tab, int l, int line);

#endif /* !PROTO_H_ */
