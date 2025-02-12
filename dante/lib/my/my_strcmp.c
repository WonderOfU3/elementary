/*
** EPITECH PROJECT, 2022
** my_strcmp
** File description:
** task06
*/

int my_strcmp(char const *s1, char const *s2)
{
    int a = 0;
    int res = 0;
    for (; s1[a] == s2[a] && s1[a] != '\0' && s2[a] != '\0'; a++);
    res = s1[a] - s2[a];
    return (res);
}
