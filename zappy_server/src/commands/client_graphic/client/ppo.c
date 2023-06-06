/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** ppo
*/

#include "zappy_server.h"
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

int ppo(my_zappy_t *zappy, int fd, char **args)
{
    char *result = NULL;

    if (zappy == NULL || args == NULL)
        return 0;
    if (count_args(args) != 2)
        return send_message(fd, "ko\n");
    if (atoi(args[1]) <= 0)
        return send_message(fd, "ko\n");
    result = get_info_player(zappy, atoi(args[1]));
    if (result == NULL)
        return send_message(fd, "ko\n");
    send_message(fd, result);
    return 0;
}