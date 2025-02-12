/*
** EPITECH PROJECT, 2023
** dante
** File description:
** my_strlen
*/

int my_strlen(char const *str)
{
    int i = 0;
    for (; str[i] != '\0'; i++);
    return (i);
}
