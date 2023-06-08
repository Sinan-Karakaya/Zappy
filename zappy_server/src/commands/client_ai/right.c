/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** right
*/

#include "zappy_server.h"
#include "commands.h"

int right(my_zappy_t *zappy, int fd, cmd_t *cmd)
{
    client_t *client = get_client_by_fd(zappy->client_list, fd);

    if (!client || !zappy || count_args(cmd->args) != 1)
        return add_cmd(cmd, "ko\n");
    if (client->info->player->direction == WEST)
        client->info->player->direction = NORTH;
    else
        client->info->player->direction += 1;
    return add_cmd(cmd, "ok\n");
}
