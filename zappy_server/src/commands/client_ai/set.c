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

static int do_set(my_zappy_t *zappy, client_t *client, int fd, size_t i)
{
    if (client->info->player->inventory[foodmap[i].value] > 0) {
    client->info->player->inventory[foodmap[i].value] -= 1;
        zappy->map->tiles[client->info->player->x]
        [client->info->player->y].inventory[foodmap[i].value] += 1;
        return send_message(fd, "ok\n");
    } else {
        return send_message(fd, "ko\n");
    }
}

int set(my_zappy_t *zappy, int fd, char **args)
{
    client_t *client = get_client_by_fd(zappy->client_list, fd);

    if (!client || !zappy || count_args(args) != 2)
        return send_message(fd, "ko\n");
    for (size_t i = 0; foodmap[i].key != NULL; i++) {
        if (strcmp(foodmap[i].key, args[1]) == 0) {
            return do_set(zappy, client, fd, i);
        }
    }
    send_message(fd, "ko\n");
    return 0;
}
