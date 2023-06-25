/*
** EPITECH PROJECT, 2023
** zappy_server
** File description:
** free_array
*/

#include "free.h"

void free_array(char **array)
{
    if (!array)
        return;
    for (int i = 0; array[i]; i++)
        free(array[i]);
    free(array);
}
