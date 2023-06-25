/*
** EPITECH PROJECT, 2023
** zappy_server
** File description:
** add_eggs
*/

#include "egg.h"
#include <stdlib.h>

static void list_add_at_back(egg_list_t *egg_list, egg_info_t *egg_info)
{
    egg_t *tmp = NULL;

    if (egg_info == NULL)
        return;
    tmp = egg_list->first;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = calloc(1, sizeof(egg_t));
    if (tmp->next == NULL)
        return;
    tmp->next->info = egg_info;
    tmp->next->next = NULL;
    tmp->next->prev = tmp;
    egg_list->last = tmp->next;
}

void list_add_eggs(egg_list_t *egg_list, egg_info_t *egg_info)
{
    egg_t *tmp = NULL;

    if (egg_info == NULL)
        return;
    if (egg_list->first == NULL) {
        tmp = calloc(1, sizeof(egg_t));
        if (tmp == NULL)
            return;
        tmp->info = egg_info;
        tmp->next = NULL;
        tmp->prev = NULL;
        egg_list->first = tmp;
        egg_list->last = tmp;
    } else {
        list_add_at_back(egg_list, egg_info);
    }
}
