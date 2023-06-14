/*
** EPITECH PROJECT, 2023
** zappy_server
** File description:
** lock_incantation
*/

#include "zappy_server.h"
#include "commands.h"

int lock_client(my_zappy_t *zappy, int fd)
{
    client_t *client = get_client_by_fd(zappy->client_list, fd);
    client_t *other = NULL;

    if (!client)
        return 84;
    client->info->player->is_incanting = true;
    for (my_id_t *tmp = zappy->map->tiles[client->info->player->y]
    [client->info->player->x].players->first; tmp; tmp = tmp->next) {
        other = get_client_by_fd(zappy->client_list, tmp->id);
        if (other == client || other->info->player->is_incanting == false)
            continue;
        if (other->info->player->lvl == client->info->player->lvl)
            other->info->player->is_incanting = true;
    }
    return 0;
}

static int level_up_client(my_zappy_t *zappy, client_t *client, bool succeed)
{
    char *message = "";

    if (succeed) {
        client->info->player->lvl++;
        asprintf(&message, "plv %d %ld\n", client->info->fd,
        client->info->player->lvl);
        send_to_graphics(zappy, message);
    }
    client->info->player->is_incanting = false;
    return 0;
}

int unlock_clients(my_zappy_t *zappy, int fd, bool succeed)
{
    client_t *client = get_client_by_fd(zappy->client_list, fd);
    client_t *other = NULL;

    if (!client)
        return 84;
    level_up_client(zappy, client, succeed);
    for (my_id_t *tmp = zappy->map->tiles[client->info->player->y]
    [client->info->player->x].players->first; tmp; tmp = tmp->next) {
        other = get_client_by_fd(zappy->client_list, tmp->id);
        if (other == client || other->info->player->is_incanting == false)
            continue;
        if (other->info->player->lvl == client->info->player->lvl)
            level_up_client(zappy, other, succeed);
    }
    return 0;
}

