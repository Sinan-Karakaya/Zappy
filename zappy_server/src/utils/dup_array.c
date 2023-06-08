/*
** EPITECH PROJECT, 2023
** zappy_server
** File description:
** duplicate an array
*/

#include <stdlib.h>
#include <string.h>

char **dup_array(char **array)
{
    char **result = NULL;
    size_t size = 0;

    if (array == NULL)
        return NULL;
    for (; array[size] != NULL; size++);
    result = calloc(size + 1, sizeof(char *));
    if (result == NULL)
        return NULL;
    for (size_t i = 0; array[i] != NULL; i++) {
        result[i] = strdup(array[i]);
        if (result[i] == NULL)
            return NULL;
    }
    return result;
}
