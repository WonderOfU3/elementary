/*
** EPITECH PROJECT, 2022
** my_put_nbr
** File description:
** task07
*/

#include <unistd.h>
#include "antman.h"

int my_put_nbr(int nb)
{
    int resultat = 0;

    if (nb < 0){
        my_putchar('-');
        nb = nb * -1;
    }
    if (nb >= 10){
        resultat = nb % 10;
        my_put_nbr(nb / 10);
        my_put_nbr(resultat);
    }
    if (nb <= 9 && nb >= 0){
        my_putchar (nb + '0');
    }
    return 0;
}
