/*
** EPITECH PROJECT, 2022
** my_sort_int_array
** File description:
** task06
*/

void my_sort_int_array(int *array, int size)
{
    for (int i = 0, tmp = 0; i < size - 1;) {
        if (array[i] > array[i + 1]) {
            tmp = array[i];
            array[i] = array[i + 1];
            array[i + 1] = tmp;
            i = 0;
        } else
            i++;
    }
}
