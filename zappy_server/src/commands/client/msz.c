/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** msz
*/

#include "zappy_server.h"
#include "commands.h"

int msz(my_zappy_t *zappy, int fd, char **args)
{
    char *result;

    if (zappy == NULL || args == NULL)
        return 0;
    asprintf(result, "%s %d %d\n", "msz", zappy->map->x, zappy->map->y);
    send_message(fd, result);
    return 0;
}
