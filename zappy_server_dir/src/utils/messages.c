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
    char *result = calloc(1, sizeof(char));

    if (!cmd || !cmd->result)
        return 84;
    for (size_t i = 0; cmd->result[i]; i++) {
        char *temp;
        asprintf(&temp, "%s%s", result, cmd->result[i]);
        free(result);
        result = temp;
    }
    send_message(fd, result);
    free(result);
    return 0;
}

int send_to_graphics(my_zappy_t *zappy, char *message)
{
    client_t *tmp = zappy->client_list->first;

    while (tmp != NULL) {
        if (tmp->info->team_id == TEAM_ID_GRAPHIC)
            send_message(tmp->info->fd, message);
        tmp = tmp->next;
    }
    return 0;
}
