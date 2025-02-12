/*
** EPITECH PROJECT, 2022
** my_show_word_array
** File description:
** task03
*/

int my_putstr(char const *str);

int my_show_word_array(char * const *tab)
{
    for (int w = 0; tab[w] != '\0'; w++) {
        my_putstr(tab[w]);
        my_putstr("\n");
    }
    return (0);
}
