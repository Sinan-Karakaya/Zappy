/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** sgt
*/

#include "zappy_server.h"
#include "commands.h"

int sgt(my_zappy_t *zappy, NUSED int fd, cmd_t *cmd)
{
    char *result = NULL;

    if (zappy == NULL || cmd->args == NULL)
        return 84;
    if (count_args(cmd->args) != 1)
        return 84;
    asprintf(&result, "sgt %ld\n", zappy->frequency);
    add_cmd(cmd, result);
    free(result);
    return 0;
}
