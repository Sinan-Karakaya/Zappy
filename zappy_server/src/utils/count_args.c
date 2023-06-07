/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** count_args
*/

#include <stddef.h>

size_t count_args(char **args)
{
    size_t count = 0;

    if (!args)
        return 0;
    for (; args[count] != NULL; count++);
    return count;
}
