/*
** EPITECH PROJECT, 2022
** my_find_prime_sup
** File description:
** task07
*/

int my_is_prime2(int nb)
{
    if (nb == 1 || nb == 0)
        return (0);
    for (int i = 2; i < nb; i++)
        if (nb % i == 0)
            return (0);
    return (1);
}

int my_find_prime_sup(int nb)
{
    if (nb == 0 || nb == 1)
        return (2);
    for (; my_is_prime2(nb) == 0; nb++);
    return (nb);
}
