/*
** EPITECH PROJECT, 2023
** zappy_server
** File description:
** tests_get_commands
*/

#include <criterion/criterion.h>
#include "zappy_server.h"
#include "utils.h"
#include "commands.h"

Test (get_cmd, get_command)
{
    char buffer[] = "Take Chocofraise\n";
    cmd_t *cmd = init_cmd(get_command(buffer));
    for (int i = 0; cmd->args[i]; i++)
        free(cmd->args[i]);
    free(cmd->args);
    free(cmd);
}
