/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** sbp
*/

#include "zappy_server.h"
#include "commands.h"

int sbp(my_zappy_t *zappy, int fd)
{
    (void)zappy;
    (void)fd;
    send_message(fd, "sbp\n");
    return 0;
}
