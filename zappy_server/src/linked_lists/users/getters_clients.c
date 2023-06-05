/*
** EPITECH PROJECT, 2023
** B-NWP-400-REN-4-1-myteams-axel.rohee
** File description:
** getters_clients
*/

#include "zappy_server.h"
#include "clients.h"

client_info_t *get_client_info_by_id(client_list_t *list, int id)
{
    for (client_t *tmp = list->first; tmp != NULL; tmp = tmp->next) {
        if (tmp->info->user_id == id) {
            return tmp->info;
        }
    }
    return NULL;
}

client_t *get_client_by_id(client_list_t *list, int id)
{
    for (client_t *tmp = list->first; tmp != NULL; tmp = tmp->next) {
        if (tmp->info->user_id == id) {
            return tmp;
        }
    }
    return NULL;
}

client_t *get_client_by_fd(client_list_t *list, int fd)
{
    for (client_t *tmp = list->first; tmp != NULL; tmp = tmp->next) {
        if (tmp->info->fd == fd) {
            return tmp;
        }
    }
    return NULL;
}
