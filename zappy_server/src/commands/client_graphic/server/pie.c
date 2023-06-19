/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** pie
*/

#include "zappy_server.h"
#include "commands.h"

int pie(my_zappy_t *zappy, client_t *client, char *result)
{
    char *res = NULL;

    if (!client || !result)
        return 0;
    asprintf(&res, "pie %d %d %s\n", client->info->player->x,
    client->info->player->y, result);
    send_to_graphics(zappy, res);
    free(res);
    return 0;
}
