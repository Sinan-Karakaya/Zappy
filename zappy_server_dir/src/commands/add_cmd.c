/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** add_cmd
*/

#include "zappy_server.h"
#include "commands.h"

int add_cmd(cmd_t *cmd, char *str)
{
    size_t i = 0;

    if (cmd == NULL || str == NULL)
        return 84;
    if (cmd->result)
        for (; cmd->result[i] != NULL; i++);
    cmd->result = realloc(cmd->result, sizeof(char *) * (i + 2));
    cmd->result[i] = strdup(str);
    cmd->result[i + 1] = NULL;
    return 0;
}
