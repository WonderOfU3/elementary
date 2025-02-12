/*
** EPITECH PROJECT, 2022
** my_strncpy
** File description:
** task02
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    for (; src[i] != '\0' && n >= i; i++)
        dest[i] = src[i];
    if (i < n)
        dest[i] = '\0';
    return (dest);
}
