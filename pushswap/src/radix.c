/*
** EPITECH PROJECT, 2022
** pushswap
** File description:
** get_linked_lst
*/

#include "proto.h"
#include <stdlib.h>
#include <stdio.h>

void send_to_list(int size, int i, first_t *l_a, first_t *l_b)
{
    for (int z = 0; z < size; z++) {
        do_pb_pa(l_a, l_b);
        my_putstr("pa");
        if (i != 31 || z < size - 1)
            my_putchar(' ');
        else
            my_putchar('\n');
    }
}

void do_command(int len, int i, first_t *l_a, first_t *l_b)
{
    struct linked_list *element = l_a->first;
    int size = 0, k = 0;
    k = (i == 31) ? 1 : 0;
    for (int a = 0; a < len; a++) {
        if ((((element->data >> i) & 1) == k)) {
            do_pb_pa(l_b, l_a);
            size++;
            element = element->next;
            my_putstr("pb ");
        } else {
            do_ra(l_a);
            my_putstr("ra ");
        }
    }
    send_to_list(size, i, l_a, l_b);
}

void do_radix_sort(first_t *l_a, first_t *l_b, int len)
{
    for (int i = 0; i < 32; i++)
        do_command(len, i, l_a, l_b);
}

int check_number(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] != '-' && (str[i] < '0' || str[i] > '9'))
            return (84);
    return (0);
}

int main(int ac, char **av)
{
    first_t *l_a = malloc(sizeof(first_t *));
    first_t *l_b = malloc(sizeof(first_t *));
    for (int i = ac - 1; i > 0; i--) {
        if (check_number(av[i]) == 84)
            return (84);
        insert_first_elem(l_a, my_getnbr(av[i]));
    }
    do_radix_sort(l_a, l_b, ac - 1);
}
