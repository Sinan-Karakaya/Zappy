/*
** EPITECH PROJECT, 2023
** B-NWP-400-REN-4-1-myteams-axel.rohee
** File description:
** init_clients
*/

#include "clients.h"
#include "zappy_server.h"
#include <unistd.h>

client_info_t *init_clients_info(int fd)
{
    client_info_t *info = calloc(1, sizeof(client_info_t));

    if (info == NULL)
        return NULL;
    info->fd = fd;
    uuid_generate_random(info->user_uuid);
    info->username = NULL;
    info->is_logged = false;
    uuid_generate_random(info->team_uuid);
    return info;
}

void copy_clients_info(client_t *this, client_t *other)
{

    if (!this || !other)
        return;
    uuid_copy(this->info->user_uuid, other->info->user_uuid);
    this->info->username = other->info->username;
    this->info->is_logged = true;
    return;
}
