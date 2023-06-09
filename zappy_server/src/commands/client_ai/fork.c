/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** fork
*/

#include "zappy_server.h"
#include "commands.h"

int verify_fork(my_zappy_t *zappy, int fd, cmd_t *cmd)
{
    add_to_callback(zappy, fd, cmd);
    return 0;
}

int fork_cmd(my_zappy_t *zappy, int fd, cmd_t *cmd)
{
    client_t *client = get_client_by_fd(zappy->client_list, fd);

    if (!zappy || !client || count_args(cmd->args) != 1)
        return send_message(fd, "ko\n");
    printf("%s: Ici je vais ajouter un nouveau client\n", SERVER_RED);
    return 0;
}
