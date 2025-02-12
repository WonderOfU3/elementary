/*
** EPITECH PROJECT, 2022
** my_get_nbr
** File description:
** task05
*/

#include <unistd.h>

void my_putchar(char c);

void pos_neg(char const *str, int nb)
{
    int neg = 0;

    for (int i = 0; str[i] < 48 || str[i] > 57; i++)
        if (str[i] == '-')
            neg++;
    if (neg % 2 == 1 && nb != 0)
        my_putchar('-');
}

int my_lennumb(char const *str)
{
    int i = 0;

    for (; str[i] < 48 || str[i] > 57; i++);
    return (i);
}

int my_getnbr(char const *str)
{
    int nb = 0;

    for (int i = my_lennumb(str); str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9')
            nb += str[i] - '0';
        if (str[i + 1] >= '0' && str[i + 1] <= '9')
            nb *= 10;
        else {
            pos_neg(str, nb);
            return (nb);
        }
    }
    return (0);
}
