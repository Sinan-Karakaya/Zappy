/*
** EPITECH PROJECT, 2023
** zappy_server
** File description:
** destroy_eggs
*/

#include "egg.h"

#include <stdlib.h>

static size_t destroy_egg_info(egg_t *egg)
{
    if (!egg || !egg->info)
        return 84;
    free(egg->info);
    return 0;
}

size_t destroy_egg(egg_list_t *list, egg_t *egg)
{
    if (!egg)
        return 0;
    destroy_egg_info(egg);
    if (list->first == egg)
        list->first = egg->next;
    if (list->last == egg)
        list->last = egg->prev;
    if (egg->next)
        egg->next->prev = egg->prev;
    if (egg->prev)
        egg->prev->next = egg->next;
    free(egg);
    return 0;
}
