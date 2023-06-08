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
    (void)zappy;
    (void)fd;
    (void)cmd;
    return 0;
}
