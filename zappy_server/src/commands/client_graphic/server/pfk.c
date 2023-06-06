/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** pfk
*/

#include "zappy_server.h"
#include "commands.h"

int pfk(my_zappy_t *zappy, int fd)
{
    char *result = NULL;

    if (zappy == NULL)
        return 0;
    asprintf(&result, "pfk %d\n", fd);
    send_message(fd, result);
    return 0;
}
