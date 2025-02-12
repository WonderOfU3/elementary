/*
** EPITECH PROJECT, 2023
** dante
** File description:
** dante
*/

#ifndef DANTE_H_
    #define DANTE_H_

typedef struct pos_s {
    int l;
    int c;
    int max_l;
    int max_c;
} pos_t;

char *open_read(char *filepath);

char **my_str_to_word_array(char const *str);

int count_words(char const *str);

int my_strlen(char const *str);

void print_map(char **tab, char *str);

void find_path(char **tab, pos_t *p);

int check_blocked(char **tab, pos_t *p);

void get_unblocked(char **tab, pos_t *p);

char **solve_maze(char **tab, char *str, pos_t *p);

char **get_solved_map(char **tab, char *str);

char **generate_full_maze(int x, int y);

void print_maze(char **tab, int y);

char **perfect_maze(char **tab, int x, int y);

char **imperfect_maze(char **tab, int x, int y);

#endif /* DANTE_H_ */
