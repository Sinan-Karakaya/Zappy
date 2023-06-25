/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** left
*/

#include "zappy_server.h"
#include "commands.h"

int verify_left(my_zappy_t *zappy, int fd, cmd_t *cmd)
{
    add_to_callback(zappy, fd, cmd);
    return 0;
}

int left(my_zappy_t *zappy, int fd, cmd_t *cmd)
{
    client_t *client = get_client_by_fd(zappy->client_list, fd);

    if (!client || !zappy || count_args(cmd->args) != 1)
        return add_cmd(cmd, "ko\n");
    if (client->info->player->direction == NORTH)
        client->info->player->direction = WEST;
    else
        client->info->player->direction -= 1;
    send_pos_to_graphics(zappy, client);
    return add_cmd(cmd, "ok\n");
}
