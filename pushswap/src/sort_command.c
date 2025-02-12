/*
** EPITECH PROJECT, 2022
** delivery
** File description:
** bubble
*/

#include <stdio.h>
#include<stdlib.h>
#include "proto.h"

void insert_first_elem(first_t *list, int nbr)
{
    struct linked_list *new = malloc(sizeof(struct linked_list *));
    new->data = nbr;
    new->next = list->first;
    list->first = new;
}

void do_pb_pa(first_t *l_a, first_t *l_b)
{
    struct linked_list *element = l_b->first;
    if (l_b != NULL) {
        insert_first_elem(l_a, element->data);
        l_b->first = l_b->first->next;
    }
}

void do_ra(first_t *l_a)
{
    struct linked_list *element = l_a->first;
    struct linked_list *first = l_a->first;
    int tmp = first->data;
    for (int i = 0; element != NULL; i++) {
        if (i > 0) {
            first->data = element->data;
            first = first->next;
        }
        element = element->next;
    }
    first->data = tmp;
}
