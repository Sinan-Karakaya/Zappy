/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** fork
*/

#include "zappy_server.h"
#include "commands.h"

int verify_fork(my_zappy_t *zappy, int fd, char **args)
{
    add_to_callback(zappy, fd, args, args[0]);
    return 0;
}

int fork_cmd(my_zappy_t *zappy, int fd, char **args)
{
    (void)zappy;
    (void)fd;
    (void)args;
    return 0;
}
