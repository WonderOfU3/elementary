/*
** EPITECH PROJECT, 2022
** my_str_isalpha
** File description:
** task12
*/

int my_str_isalpha(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] < 'A' || (str[i] > 'Z' && str[i] < 'a') || str[i] > 'z')
            return (0);
    return (1);
}
