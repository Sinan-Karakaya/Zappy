/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** set
*/

#include "zappy_server.h"
#include "commands.h"

static key_value_t foodmap[] = {
    {"food", FOOD},
    {"linemate", LINEMATE},
    {"deraumere", DERAUMERE},
    {"sibur", SIBUR},
    {"mendiane", MENDIANE},
    {"phiras", PHIRAS},
    {"thystame", THYSTAME},
    {NULL, 0}
};

static int do_set(my_zappy_t *zappy, client_t *client, size_t i)
{
    if (client->info->player->inventory[foodmap[i].value] > 0) {
        client->info->player->inventory[foodmap[i].value] -= 1;
        zappy->map->tiles[client->info->player->x]
        [client->info->player->y].inventory[foodmap[i].value] += 1;
        return 1;
    } else
        return 0;
}

int set(my_zappy_t *zappy, int fd, cmd_t *cmd)
{
    client_t *client = get_client_by_fd(zappy->client_list, fd);
    int ret = 0;

    if (!client || !zappy || count_args(cmd->args) != 2)
        return add_cmd(cmd, "ko\n");
    for (size_t i = 0; foodmap[i].key != NULL; i++) {
        if (strcmp(foodmap[i].key, cmd->args[1]) == 0)
            ret = do_set(zappy, client, i);
    }
    if (ret == 1)
        return add_cmd(cmd, "ok\n");
    return add_cmd(cmd, "ko\n");
}
