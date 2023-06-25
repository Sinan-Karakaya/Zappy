/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** look
*/

#include "zappy_server.h"
#include "commands.h"

int look(my_zappy_t *zappy, int fd, cmd_t *cmd)
{
    client_t *client = get_client_by_fd(zappy->client_list, fd);

    if (!client || !zappy || count_args(cmd->args) != 1)
        return add_cmd(cmd, "ko\n");
    if (client->info->player->direction == NORTH)
        look_up(client, zappy->map, cmd);
    if (client->info->player->direction == EAST)
        look_right(client, zappy->map, cmd);
    if (client->info->player->direction == SOUTH)
        look_down(client, zappy->map, cmd);
    if (client->info->player->direction == WEST)
        look_left(client, zappy->map, cmd);
    return 0;
}
