/*
** EPITECH PROJECT, 2023
** zappy_server
** File description:
** verify_look
*/

#include "zappy_server.h"
#include "commands.h"

int verify_look(my_zappy_t *zappy, int fd, char **args)
{
    add_to_callback(zappy, fd, args, args[0]);
    return 0;
}
