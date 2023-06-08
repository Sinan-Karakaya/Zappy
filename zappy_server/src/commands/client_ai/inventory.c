/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** inventory
*/

#include "zappy_server.h"
#include "commands.h"

int verify_inventory(my_zappy_t *zappy, int fd, char **args)
{
    add_to_callback(zappy, fd, args, args[0]);
    return 0;
}

int inventory(my_zappy_t *zappy, int fd, char **args)
{
    client_t *client = get_client_by_fd(zappy->client_list, fd);
    char *msg = "";

    if (!client || !zappy || count_args(args) != 1)
        return send_message(fd, "ko\n");
    asprintf(&msg, "[ food %ld, linemate %ld, deraumere %ld, sibur %ld, "
        "mendiane %ld, phiras %ld, thystame %ld ]\n",
        client->info->player->inventory[FOOD],
        client->info->player->inventory[LINEMATE],
        client->info->player->inventory[DERAUMERE],
        client->info->player->inventory[SIBUR],
        client->info->player->inventory[MENDIANE],
        client->info->player->inventory[PHIRAS],
        client->info->player->inventory[THYSTAME]);
    send_message(fd, msg);
    return 0;
}
