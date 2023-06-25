/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** suc
*/

#include "zappy_server.h"
#include "commands.h"

int suc(my_zappy_t *zappy, int fd)
{
    (void)zappy;
    send_message(fd, "suc\n");
    return 0;
}
