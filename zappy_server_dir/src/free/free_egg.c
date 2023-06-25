/*
** EPITECH PROJECT, 2023
** zappy_server
** File description:
** free_egg
*/

#include "free.h"

void free_egg_list(egg_list_t *egg_list)
{
    egg_t *current = NULL;
    egg_t *next = NULL;

    if (!egg_list)
        return;
    current = egg_list->first;
    while (current) {
        next = current->next;
        if (current->info)
            free(current->info);
        free(current);
        current = next;
    }
    free(egg_list);
}
