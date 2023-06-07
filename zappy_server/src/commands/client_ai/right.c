/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** right
*/

#include "zappy_server.h"
#include "commands.h"

int right(my_zappy_t *zappy, int fd, char **args)
{
    client_t *client = get_client_by_fd(zappy->client_list, fd);

    if (!client || !zappy || count_args(args) != 1)
        return send_message(fd, "ko\n");
    if (client->info->player->direction == WEST)
        client->info->player->direction = NORTH;
    else
        client->info->player->direction += 1;
    send_message(fd, "ok\n");
    return 0;
}
