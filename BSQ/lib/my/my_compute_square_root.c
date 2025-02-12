/*
** EPITECH PROJECT, 2022
** my_compute_square_root
** File description:
** task05
*/

int my_compute_square_root(int nb)
{
    for (int a = 1; a <= nb; a++)
        if (a * a == nb)
            return (a);
    return (0);
}
