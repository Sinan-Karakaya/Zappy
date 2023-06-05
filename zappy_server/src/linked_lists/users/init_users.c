/*
** EPITECH PROJECT, 2023
** B-NWP-400-REN-4-1-myteams-axel.rohee
** File description:
** init_clients
*/

#include "clients.h"
#include "zappy_server.h"
#include <unistd.h>

// mettre la pos en random sur la map
// mettre la direction en random
// faire le action_time + death_timer
static player_t *init_player(void)
{
    player_t *new_player = calloc(1, sizeof(player_t));

    if (new_player == NULL)
        return NULL;
    new_player->x = 0;
    new_player->y = 0;
    new_player->id = 0;
    new_player->direction = NORTH;
    new_player->lvl = 1;
    new_player->action_time = 0;
    new_player->eat_timer = 0;
    for (size_t i = 0; i < LENGHT_INVENTORY; i++)
        new_player->inventory[i] = 0;
    new_player->inventory[FOOD] = 10;
    new_player->id = 0;
    return new_player;
}

client_info_t *init_clients_info(int fd)
{
    client_info_t *info = calloc(1, sizeof(client_info_t));

    if (info == NULL)
        return NULL;
    info->fd = fd;
    info->user_id = fd;
    info->team_id = -1;
    info->player = init_player();
    return info;
}
