/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** tna
*/

#include "zappy_server.h"
#include "commands.h"

int tna(my_zappy_t *zappy, int fd, cmd_t *cmd)
{
    char *result = NULL;
    team_t *tmp = NULL;

    if (zappy == NULL || cmd->args == NULL)
        return 0;
    if (count_args(cmd->args) != 1) {
        send_message(fd, "ko\n");
        return 0;
    } tmp = zappy->team_list->first;
    result = calloc(1, sizeof(char));
    while (tmp != NULL) {
        result = realloc(result, sizeof(char) * (strlen(result) + \
            strlen(tmp->info->name) + 6));
        result = strcat(result, "tna ");
        result = strcat(result, tmp->info->name);
        result = strcat(result, "\n");
        tmp = tmp->next;
    }
    return add_cmd(cmd, result);
}
