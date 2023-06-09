/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** cmd_init
*/

#include "commands.h"
#include "utils.h"

cmd_t *init_cmd(char **args)
{
    cmd_t *cmd = calloc(1, sizeof(cmd_t));

    if (cmd == NULL)
        return NULL;
    cmd->args = dup_array(args);
    cmd->result = calloc(1, sizeof(char *));
    if (cmd->result == NULL)
        return NULL;
    return cmd;
}
