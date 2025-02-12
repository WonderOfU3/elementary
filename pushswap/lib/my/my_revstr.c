/*
** EPITECH PROJECT, 2022
** my_revstr
** File description:
** task03
*/

int my_strlen2(char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return (i);
}

char *my_revstr(char *str)
{
    char temp;

    for (int a = 0, b = my_strlen2(str) - 1; a < b; a++, b--) {
        temp = str[a];
        str[a] = str[b];
        str[b] = temp;
    }
    return (str);
}
