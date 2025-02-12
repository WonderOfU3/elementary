/*
** EPITECH PROJECT, 2022
** my_strncmp
** File description:
** task07
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int a = 0;
    int res = 0;

    for (; s1[a] == s2[a] && n >= a; a++);
    res = s1[a] - s2[a];
    return (res);
}
