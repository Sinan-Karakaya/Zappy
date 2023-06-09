/*
** EPITECH PROJECT, 2023
** B-NWP-400-REN-4-1-myteams-axel.rohee
** File description:
** add_clients
*/

#include "zappy_server.h"
#include "clients.h"

static void list_add_at_back(client_list_t *list, client_info_t *info)
{
    client_t *tmp = NULL;

    if (info == NULL)
        return;
    tmp = list->first;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = calloc(1, sizeof(client_t));
    if (tmp->next == NULL)
        return;
    tmp->next->info = info;
    tmp->next->next = NULL;
    tmp->next->prev = tmp;
    list->last = tmp->next;
}

void list_add_client(client_list_t *list, client_info_t *info)
{
    client_t *tmp = NULL;

    if (info == NULL)
        return;
    if (list->first == NULL) {
        tmp = malloc(sizeof(client_t));
        if (tmp == NULL)
            return;
        tmp->info = info;
        tmp->next = NULL;
        tmp->prev = NULL;
        list->first = tmp;
        list->last = tmp;
    } else {
        list_add_at_back(list, info);
    }
}

static void list_add_at_back_id(id_list_t *list, int id)
{
    my_id_t *tmp = NULL;

    if (list == NULL)
        return;
    tmp = list->first;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = calloc(1, sizeof(my_id_t));
    if (tmp->next == NULL)
        return;
    tmp->next->id = id;
    tmp->next->next = NULL;
    tmp->next->prev = tmp;
    list->last = tmp->next;
}

void list_add_id(id_list_t *list, int id)
{
    my_id_t *tmp = NULL;

    if (list == NULL)
        return;
    if (list->first == NULL) {
        tmp = calloc(1, sizeof(my_id_t));
        if (tmp == NULL)
            return;
        tmp->id = id;
        tmp->next = NULL;
        tmp->prev = NULL;
        list->first = tmp;
        list->last = tmp;
    } else {
        list_add_at_back_id(list, id);
    }
}
