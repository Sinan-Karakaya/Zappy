/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** sst
*/

#include "zappy_server.h"
#include "commands.h"

int sst(my_zappy_t *zappy, int fd, cmd_t *cmd)
{
    char *result = NULL;

    if (zappy == NULL || cmd->args == NULL)
        return 84;
    if (count_args(cmd->args) != 2)
        return send_message(fd, "ko\n");
    zappy->frequency = atoi(cmd->args[1]);
    asprintf(&result, "sgt %ld\n", zappy->frequency);
    return add_cmd(cmd, result);
}
