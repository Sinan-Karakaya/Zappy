/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** eject
*/

#include "zappy_server.h"
#include "commands.h"
#include "utils.h"

int eject(my_zappy_t *zappy, int fd, cmd_t *cmd)
{
    client_t *client = get_client_by_fd(zappy->client_list, fd);
    vector_t coordinates = real_coordinates(client, zappy->map);
    char *result = NULL;

    if (!zappy || !cmd || !cmd->args || !client || count_args(cmd->args) != 1)
        return add_cmd(cmd, "ko\n");
    asprintf(&result, "pex %ld\n", client->info->player->id);
    for (my_id_t *tmp = zappy->map->tiles[client->info->player->y]
    [client->info->player->x].players->first; tmp; tmp = tmp->next) {
        client_t *tmp_client = get_client_by_fd(zappy->client_list, tmp->id);
        if (tmp_client != client) {
            tmp_client->info->player->x = coordinates.x;
            tmp_client->info->player->y = coordinates.y;
            send_message(tmp_client->info->fd, result);
        }
    }
    return add_cmd(cmd, "ok\n");
}
