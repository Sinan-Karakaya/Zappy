/*
** EPITECH PROJECT, 2023
** zappy_server
** File description:
** add_callback
*/

#include "callback.h"
#include <stdlib.h>

static void list_add_at_back(callback_list_t *callback_list,
callback_info_t *callback_info)
{
    callback_t *tmp = NULL;

    if (callback_info == NULL)
        return;
    tmp = callback_list->first;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = calloc(1, sizeof(callback_t));
    if (tmp->next == NULL)
        return;
    tmp->next->info = callback_info;
    tmp->next->next = NULL;
    tmp->next->prev = tmp;
    callback_list->last = tmp->next;
}

void list_add_callback(callback_list_t *callback_list,
callback_info_t *callback_info)
{
    callback_t *tmp = NULL;

    if (callback_info == NULL)
        return;
    if (callback_list->first == NULL) {
        tmp = calloc(1, sizeof(callback_t));
        if (tmp == NULL)
            return;
        tmp->info = callback_info;
        tmp->next = NULL;
        tmp->prev = NULL;
        callback_list->first = tmp;
        callback_list->last = tmp;
    } else {
        list_add_at_back(callback_list, callback_info);
    }
}
