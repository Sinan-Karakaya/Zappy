/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** pin
*/

#include "commands.h"
#include "free.h"

static char *get_info_player(my_zappy_t *zappy, int id)
{
    char *result = NULL;
    client_info_t *client = NULL;

    if (zappy == NULL)
        return NULL;
    client = get_client_info_by_id(zappy->client_list, id);
    if (client == NULL)
        return NULL;
    asprintf(&result, "pin %d %d %d %ld %ld %ld %ld %ld %ld %ld\n", client->fd,
    client->player->x, client->player->y, client->player->inventory[FOOD],
    client->player->inventory[LINEMATE], client->player->inventory[DERAUMERE],
    client->player->inventory[SIBUR], client->player->inventory[MENDIANE],
    client->player->inventory[PHIRAS], client->player->inventory[THYSTAME]);
    return result;
}

int pin(my_zappy_t *zappy, NUSED int fd, cmd_t *cmd)
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
