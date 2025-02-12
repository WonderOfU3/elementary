/*
** EPITECH PROJECT, 2022
** my_strcapitalize
** File description:
** task10
*/

char *my_strcapitalize(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i - 1] == ' ' || i == 0) && str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
    }
    return (str);
}
