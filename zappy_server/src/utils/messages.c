/*
** EPITECH PROJECT, 2023
** B-NWP-400-REN-4-1-myftp-thomas.juin
** File description:
** messages
*/

#include "commands.h"
#include <stdio.h>

int send_message(int fd, char *message)
{
    if (dprintf(fd, "%s", message) == -1)
        return (84);
    return (0);
}

int send_message_lb(int fd, char *message)
{
    if (dprintf(fd, "%s\n", message) == -1)
        return (84);
    return (0);
}

int send_message_error(int fd, char *message)
{
    if (dprintf(fd, "%s", message) == -1)
        return (84);
    return (1);
}

int send_all_message(cmd_t *cmd, int fd)
{
    char *result = "";

    if (!cmd || !cmd->result)
        return 84;
    for (size_t i = 0; cmd->result[i]; i++)
        asprintf(&result, "%s%s", result, cmd->result[i]);
    return send_message(fd, result);
}
