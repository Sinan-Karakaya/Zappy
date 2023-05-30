/*
** EPITECH PROJECT, 2023
** B-NWP-400-REN-4-1-myteams-axel.rohee
** File description:
** destroy_uuid
*/

#include "zappy_server.h"
#include "clients.h"

static void delete_uuid(uuid_list_t *list, my_uuid_t *tmp)
{
    if (list->first == tmp)
        list->first = tmp->next;
    if (list->last == tmp)
        list->last = tmp->prev;
    if (tmp->next)
        tmp->next->prev = tmp->prev;
    if (tmp->prev)
        tmp->prev->next = tmp->next;
    free(tmp);
}

int remove_uuid_in_list(uuid_list_t *list, uuid_t uuid)
{
    my_uuid_t *tmp = NULL;

    if (!list)
        return 0;
    tmp = list->first;
    for (tmp = list->first; tmp; tmp = tmp->next) {
        if (uuid_compare(tmp->uuid, uuid) == 0) {
            delete_uuid(list, tmp);
            return 0;
        }
    }
    return 1;
}
