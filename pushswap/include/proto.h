/*
** EPITECH PROJECT, 2022
** delivery
** File description:
** proto
*/

#ifndef PROTO_H_
    #define PROTO_H_

typedef struct linked_list {
    int data;
    struct linked_list *next;
}linked_list;

typedef struct first_s {
    struct linked_list *first;
}first_t;

int my_getnbr(char const *str);

int my_putstr(char const *str);

void my_putchar(char c);

void do_pb_pa(first_t *l_a, first_t *l_b);

void do_ra(first_t *l_a);

void insert_first_elem(first_t *list, int nbr);

void delete_first_elem(first_t *list);

#endif /* !PROTO_H_ */
