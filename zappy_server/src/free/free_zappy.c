/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** free_all
*/

#include "free.h"
#include <stdlib.h>

static void disconnect_all_clients(my_zappy_t *zappy)
{
    client_t *tmp = NULL;

    for (client_t *client = zappy->client_list->first; client;) {
        tmp = client;
        client = client->next;
        disconnect_player(zappy, tmp->info->fd);
    }
}

size_t free_zappy(my_zappy_t *zappy)
{
    disconnect_all_clients(zappy);
    close(zappy->server->sockfd);
    free(zappy->server);
    free_client_list(zappy->client_list);
    free(zappy->callback_list);
    free_egg_list(zappy->egg_list);
    free_team_list(zappy->team_list);
    if (zappy->time)
        free(zappy->time);
    destroy_map(zappy->map);
    free(zappy);
    return 0;
}
