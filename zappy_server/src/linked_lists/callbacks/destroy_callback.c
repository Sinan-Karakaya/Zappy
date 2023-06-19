/*
** EPITECH PROJECT, 2023
** zappy_server
** File description:
** destroy_callbacks
*/

#include "callback.h"
#include <stdlib.h>

static size_t destroy_callback_info(callback_t *callback)
{
    if (!callback || !callback->info)
        return 84;
    for (size_t i = 0; callback->info->cmd->args[i] != NULL; i++)
        free(callback->info->cmd->args[i]);
    free(callback->info->cmd->args);
    free(callback->info);
    return 0;
}

size_t destroy_callback(callback_list_t *list, callback_t *callback)
{
    if (!callback)
        return 0;
    destroy_callback_info(callback);
    if (list->first == callback)
        list->first = callback->next;
    if (list->last == callback)
        list->last = callback->prev;
    if (callback->next)
        callback->next->prev = callback->prev;
    if (callback->prev)
        callback->prev->next = callback->next;
    free(callback);
    return 0;
}
