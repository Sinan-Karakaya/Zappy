/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** send_pos_to_graphics
*/

#include "zappy_server.h"
#include "commands.h"

int send_pos_to_graphics(my_zappy_t *zappy, client_t *client)
{
    char *msg = NULL;

    if (!zappy || !client)
        return 84;
    asprintf(&msg, "ppo %ld %d %d %d\n", client->info->player->id,
    client->info->player->x, client->info->player->y,
    client->info->player->direction);
    send_to_graphics(zappy, msg);
    free(msg);
    return 0;
}

int send_inventory_to_graphics(my_zappy_t *zappy, client_t *client)
{
    char *msg = NULL;

    if (!zappy || !client)
        return 84;
    asprintf(&msg, "pin %ld %d %d %ld %ld %ld %ld %ld %ld %ld\n",
    client->info->player->id, client->info->player->x,
    client->info->player->y, client->info->player->inventory[FOOD],
    client->info->player->inventory[LINEMATE],
    client->info->player->inventory[DERAUMERE],
    client->info->player->inventory[SIBUR],
    client->info->player->inventory[MENDIANE],
    client->info->player->inventory[PHIRAS],
    client->info->player->inventory[THYSTAME]);
    send_to_graphics(zappy, msg);
    free(msg);
    return 0;
}
