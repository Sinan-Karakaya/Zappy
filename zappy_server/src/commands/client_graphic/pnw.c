/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** pnw
*/

#include "zappy_server.h"
#include "commands.h"

// pnw #n X Y O L N\n
int pnw(my_zappy_t *zappy, int fd)
{
    char *result = NULL;
    client_t *client = NULL;
    team_t *team = NULL;

    if (zappy == NULL)
        return 0;
    client = get_client_by_fd(zappy->client_list, fd);
    team = get_team_by_uuid(zappy->team_list, (char *)client->info->team_uuid);
    asprintf(&result, "pnw %ld %d %d %d %ld %s\n", client->info->player->id,
        client->info->player->x, client->info->player->y,
        client->info->player->direction, client->info->player->lvl,
        team->info->name);
    send_message(fd, result);
    return 0;
}