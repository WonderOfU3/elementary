/*
** EPITECH PROJECT, 2022
** concat_params
** File description:
** task02
*/

#include <stdlib.h>

int my_strlen(char const *str);

int my_putstr(char const *str);

char *concat_params(int argc, char **argv)
{
    char *str;
    int len = argc;
    int i = 0;

    for (int i = 0; i < argc; i++)
        len += my_strlen(argv[i]);
    str = malloc(sizeof(char) * (len + 1));
    for (int a = 0, b = 0; i < len; i++) {
        str[i] = argv[a][b];
        b++;
        if (argv[a][b] == '\0' && a != argc - 1) {
            b = 0;
            a++;
            i++;
            str[i] = '\n';
        }
    }
    return (str);
}
