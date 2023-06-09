/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** msz
*/

#include "zappy_server.h"
#include "commands.h"

int msz(my_zappy_t *zappy, NUSED int fd, cmd_t *cmd)
{
    char *result = NULL;

    if (zappy == NULL || cmd == NULL)
        return 0;
    if (count_args(cmd->args) != 1)
        return add_cmd(cmd, "ko\n");
    asprintf(&result, "%s %ld %ld\n", "msz", zappy->map->x, zappy->map->y);
    add_cmd(cmd, result);
    free(result);
    return 0;
}
