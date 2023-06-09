/*
** EPITECH PROJECT, 2023
** zappy_server
** File description:
** verify_look
*/

#include "zappy_server.h"
#include "commands.h"

int verify_look(my_zappy_t *zappy, int fd, cmd_t *cmd)
{
    add_to_callback(zappy, fd, cmd);
    return 0;
}
