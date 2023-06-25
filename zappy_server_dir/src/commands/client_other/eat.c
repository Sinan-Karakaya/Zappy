/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** eat
*/

#include "zappy_server.h"

static int eat(client_t *client)
{
    if (client->info->player->inventory[FOOD] > 0) {
        client->info->player->inventory[FOOD] -= 1;
        client->info->player->last_tick = client->info->player->actual_tick;
        return 0;
    }
    client->info->player->is_alive = false;
    return 0;
}

int eat_all_client(my_zappy_t *zappy)
{
    client_t *tmp = zappy->client_list->first;

    if (zappy->client_list->first == NULL)
        return 0;
    for (client_t *actual = zappy->client_list->first; tmp; actual = tmp) {
        if (actual->info->team_id <= TEAM_ID_GRAPHIC) {
            tmp = actual->next;
            continue;
        }
        if (actual->info->player->last_tick != tmp->info->player->actual_tick
        && actual->info->player->actual_tick % 126 == 0)
            eat(actual);
        if (actual->info->player->is_alive == false) {
            tmp = actual->next;
            send_message(actual->info->fd, DEATH);
            disconnect_player(zappy, actual->info->fd);
        } else
            tmp = actual->next;
    }
    return 0;
}
