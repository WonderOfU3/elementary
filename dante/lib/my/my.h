/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** task02
*/

#ifndef MY_H_
    #define MY_H_

void my_putchar(char c);

int my_isneg(int nb);

int my_put_nbr(int nb);

void my_swap(int *a, int *b);

int my_putstr(char const *str);

int my_strlen(char const *str);

int my_getnbr(char const *str);

void my_sort_int_array(int *tab, int size);

int my_compute_power_rec(int nb, int power);

int my_compute_square_root(int nb);

int my_is_prime(int nb);

int my_find_prime_sup(int nb);

char *my_strcpy(char *dest, char const *src);

char *my_strncpy(char *dest, char const *src, int n);

char *my_revstr(char *str);

char *my_strstr(char *str, char const *to_find);

int my_strcmp(char const *s1, char const *s2);

int my_strncmp(char const *s1, char const *s2, int n);

char *my_strupcase(char *str);

char *my_strlowcase(char *str);

char *my_strcapitalize(char *str);

int my_str_isalpha(char const *str);

int my_str_isnum(char const *str);

int my_str_islower(char const *str);

int my_str_isupper(char const *str);

int my_str_isprintable(char const *str);

int my_showstr(char const *str);

int my_showmem(char const *str, int size);

char *my_strcat(char *dest, char const *src);

char *my_strncat(char *dest, char const *src, int nb);

char *concat_params(int argc, char **argv);

int my_is_prime2(int nb);

int my_lennumb(char const *str);

int pos_neg(char const *str, int nb);

void print_extreme(void);

int my_strlen2(char *str);

int my_show_word_array(char * const *tab);

char *my_strdup(char const *str);

int my_len(char *str);

int count_words(char const *str);

int is_char(char c);

int my_strlen_changed(char const *str, int i);

char **my_str_to_word_array(char const *str);

linked_list_t *my_params_to_list(int ac, char * const *av);

int my_list_size(linked_list_t const *begin);

void my_rev_list(linked_list_t **begin);

#endif /* MY_H_ */
