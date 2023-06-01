/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** bct
*/

#include "zappy_server.h"
#include "commands.h"

int bct(my_zappy_t *zappy, int fd, char **args)
{
    char *result = NULL;

    if (zappy == NULL || args == NULL)
        return 0;
    if (count_args(args) != 3) {
        send_message(fd, "Bad arguments\n");
        return 0;
    }
    asprintf(&result, "bct %s %s %d %d %d %d %d %d %d\n", args[1], args[2],
        zappy->map[FOOD],
        zappy->map[LINEMATE],
        zappy->map[DERAUMERE],
        zappy->map[SIBUR],
        zappy->map[MENDIANE],
        zappy->map[PHIRAS],
        zappy->map[THYSTAME]);
    send_message(fd, result);
    return 0;
}
