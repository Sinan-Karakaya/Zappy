/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** sst
*/

#include "zappy_server.h"
#include "commands.h"

int sst(my_zappy_t *zappy, NUSED int fd, cmd_t *cmd)
{
    char *result = NULL;
    int value = 0;

    if (zappy == NULL || cmd->args == NULL)
        return 84;
    if (count_args(cmd->args) != 2)
        return add_cmd(cmd, "ko\n");
    value = atoi(cmd->args[1]);
    if (value <= 1 || value > 10000)
        return add_cmd(cmd, UNKNOWN_PARAMETER);
    zappy->frequency = value;
    refresh_time_per_tick(zappy);
    asprintf(&result, "sgt %ld\n", zappy->frequency);
    add_cmd(cmd, result);
    free(result);
    return 0;
}
