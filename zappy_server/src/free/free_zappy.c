/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** free_all
*/

#include "zappy_server.h"
#include <stdlib.h>

static size_t free_teams(my_zappy_t *zappy)
{
    if (!zappy)
        return 84;
    if (zappy->team_list) {
        for (team_t *tmp = zappy->team_list->first; tmp;
        tmp = zappy->team_list->first)
            destroy_team(zappy->team_list, tmp);
        free(zappy->team_list);
        zappy->team_list = NULL;
    }
    return 0;
}

size_t free_zappy(my_zappy_t *zappy)
{
    close(zappy->server->sockfd);
    free(zappy->server);
    free(zappy->client_list);
    free_teams(zappy);
    free(zappy);
    return 0;
}