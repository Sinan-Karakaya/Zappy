/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** quit
*/

#include "zappy_server.h"
#include "commands.h"

int quit(my_zappy_t *zappy, int fd, char **args)
{
    (void)zappy;
    (void)args;
    (void)fd;
    send_message(fd, "Goodbye\n");
    return 0;
}
