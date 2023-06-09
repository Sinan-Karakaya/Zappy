/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** ppo
*/

#include "free.h"
#include "commands.h"
#include <ctype.h>

static char *get_info_player(my_zappy_t *zappy, int id)
{
    char *result = NULL;
    client_info_t *client = NULL;

    if (zappy == NULL)
        return NULL;
    client = get_client_info_by_id(zappy->client_list, id);
    if (client == NULL)
        return NULL;
    asprintf(&result, "ppo %ld %d %d %d\n", client->player->id,
        client->player->x, client->player->y, client->player->direction);
    return result;
}

int ppo(my_zappy_t *zappy, NUSED int fd, cmd_t *cmd)
{
    char *result = NULL;

    if (zappy == NULL || cmd->args == NULL)
        return 0;
    if (count_args(cmd->args) != 2)
        return add_cmd(cmd, "ko\n");
    if (atoi(cmd->args[1]) <= 0)
        return add_cmd(cmd, "ko\n");
    result = get_info_player(zappy, atoi(cmd->args[1]));
    if (result == NULL)
        return add_cmd(cmd, "ko\n");
    add_cmd(cmd, result);
    free(result);
    return 0;
}
