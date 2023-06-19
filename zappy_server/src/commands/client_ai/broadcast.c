/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** broadcast
*/

#include "zappy_server.h"
#include "commands.h"

int verify_broadcast(my_zappy_t *zappy, int fd, cmd_t *cmd)
{
    add_to_callback(zappy, fd, cmd);
    return 0;
}

int broadcast(my_zappy_t *zappy, int fd, cmd_t *cmd)
{
    client_t *client = get_client_by_fd(zappy->client_list, fd);
    char *msg = "";

    if (!zappy || !client || count_args(cmd->args) != 2)
        return 84;
    send_message(fd, "ok\n");
    pbc(zappy, fd, cmd->args[1]);
    for (client_t *tmp = zappy->client_list->first; tmp; tmp = tmp->next) {
        if (tmp != client && tmp->info->team_id != TEAM_ID_GRAPHIC) {
            asprintf(&msg, "message %ld, %s\n",
            get_real_direction(tmp->info->player->direction,
            get_direction(client, tmp)), cmd->args[1]);
            send_message(tmp->info->fd, msg);
            free(msg);
        }
    }
    return 0;
}
