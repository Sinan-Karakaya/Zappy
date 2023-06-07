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
    char *result = NULL;

    if (zappy == NULL || args == NULL)
        return 0;
    if (count_args(args) != 1)
        return send_message(fd, "ko\n");
    asprintf(&result, "%s %ld %ld\n", "msz", zappy->map->x, zappy->map->y);
    send_message(fd, result);
    return 0;
}