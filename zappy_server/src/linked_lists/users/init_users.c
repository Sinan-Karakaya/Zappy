/*
** EPITECH PROJECT, 2023
** B-NWP-400-REN-4-1-myteams-axel.rohee
** File description:
** init_clients
*/

#include "zappy_server.h"
#include <unistd.h>

static int init_player_bis(player_t *new_player)
{
    new_player->is_action = false;
    new_player->is_incanting = false;
    new_player->is_alive = true;
    return 0;
}

static player_t *init_player(int width, int height)
{
    player_t *new_player = calloc(1, sizeof(player_t));

    if (new_player == NULL)
        return NULL;
    new_player->x = rand() % width + 0;
    new_player->y = rand() % height + 0;
    new_player->id = 0;
    new_player->direction = rand() % WEST + NORTH;
    new_player->lvl = 1;
    new_player->action_time = 0;
    for (size_t i = 0; i < LENGHT_INVENTORY; i++)
        new_player->inventory[i] = 0;
    new_player->inventory[FOOD] = 10;
    new_player->id = 0;
    new_player->actual_tick = 0;
    new_player->last_tick = 0;
    init_player_bis(new_player);
    return new_player;
}

client_info_t *init_clients_info(int fd, int width, int height)
{
    client_info_t *info = calloc(1, sizeof(client_info_t));

    if (info == NULL)
        return NULL;
    info->fd = fd;
    info->user_id = fd;
    info->team_id = -1;
    info->lst_cmd = calloc(1, sizeof(lst_commands_t));
    if (info->lst_cmd == NULL)
        return NULL;
    info->lst_cmd->first = NULL;
    info->lst_cmd->last = NULL;
    info->player = init_player(width, height);
    info->player->id = fd;
    return info;
}
