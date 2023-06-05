/*
** EPITECH PROJECT, 2023
** B-NWP-400-REN-4-1-myteams-axel.rohee
** File description:
** getters_clients
*/

#include "zappy_server.h"
#include "clients.h"

client_info_t *get_client_info_by_uuid(client_list_t *list, char *uuid)
{
    char *char_uuid = NULL;

    for (client_t *tmp = list->first; tmp != NULL; tmp = tmp->next) {
        char_uuid = uuid_to_char(tmp->info->user_uuid);
        if (strcmp(char_uuid, uuid) == 0) {
            return tmp->info;
        }
    }
    return NULL;
}

client_info_t *get_client_info_by_id(client_list_t *list, int id)
{
    for (client_t *tmp = list->first; tmp != NULL; tmp = tmp->next)
        if (tmp->info->player->id == (size_t)id)
            return tmp->info;
    return NULL;
}

client_t *get_client_by_uuid(client_list_t *list, char *uuid)
{
    char *char_uuid = NULL;

    for (client_t *tmp = list->first; tmp != NULL; tmp = tmp->next) {
        char_uuid = uuid_to_char(tmp->info->user_uuid);
        if (strcmp(char_uuid, uuid) == 0) {
            free(char_uuid);
            return tmp;
        }
        free(char_uuid);
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
