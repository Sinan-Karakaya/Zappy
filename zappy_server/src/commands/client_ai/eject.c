/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** eject
*/

#include "zappy_server.h"
#include "commands.h"
#include "utils.h"

int verify_eject(my_zappy_t *zappy, int fd, cmd_t *cmd)
{
    add_to_callback(zappy, fd, cmd);
    return 0;
}

int eject(my_zappy_t *zappy, int fd, cmd_t *cmd)
{
    client_t *client = get_client_by_fd(zappy->client_list, fd);
    vector_t coordinates = real_coordinates(client, zappy->map);

    if (!zappy || !cmd || !cmd->args || !client || count_args(cmd->args) != 1)
        return send_message(fd, "ko\n");
    for (my_id_t *tmp = zappy->map->tiles[client->info->player->y]
    [client->info->player->x].players->first; tmp; tmp = tmp->next) {
        client_t *tmp_client = get_client_by_fd(zappy->client_list, tmp->id);
        if (tmp_client != client) {
            tmp_client->info->player->x = coordinates.x;
            tmp_client->info->player->y = coordinates.y;
            send_message(tmp_client->info->fd, "Eject: LADIRECTION\n");
        }
    }
    return add_cmd(cmd, "ok\n");
}