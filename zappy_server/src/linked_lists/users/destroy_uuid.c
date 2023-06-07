/*
** EPITECH PROJECT, 2023
** B-NWP-400-REN-4-1-myteams-axel.rohee
** File description:
** destroy_id
*/

#include "zappy_server.h"
#include "clients.h"

static void delete_id(id_list_t *list, my_id_t *tmp)
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

int remove_id_in_list(id_list_t *list, int id)
{
    my_id_t *tmp = NULL;

    if (!list)
        return 0;
    tmp = list->first;
    for (tmp = list->first; tmp; tmp = tmp->next) {
        if (tmp->id == id) {
            delete_id(list, tmp);
            return 0;
        }
    }
    return 1;
}
