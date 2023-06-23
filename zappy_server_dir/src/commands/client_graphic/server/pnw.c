/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** pnw
*/

#include "zappy_server.h"
#include "commands.h"

int pnw(my_zappy_t *zappy, int fd)
{
    char *result = NULL;
    client_t *client = NULL;
    team_t *team = NULL;

    if (zappy == NULL)
        return 0;
    client = get_client_by_fd(zappy->client_list, fd);
    if (!client)
        return 0;
    team = get_team_by_id(zappy->team_list, client->info->team_id);
    if (!team)
        return 0;
    asprintf(&result, "pnw %ld %d %d %d %ld %s\n", client->info->player->id,
        client->info->player->x, client->info->player->y,
        client->info->player->direction, client->info->player->lvl,
        team->info->name);
    send_to_graphics(zappy, result);
    free(result);
    return 0;
}
