/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** free_all
*/

#include "free.h"
#include <stdlib.h>

size_t free_zappy(my_zappy_t *zappy)
{
    close(zappy->server->sockfd);
    free(zappy->server);
    free_client_list(zappy->client_list);
    free(zappy->callback_list);
    free_egg_list(zappy->egg_list);
    free_team_list(zappy->team_list);
    if (zappy->time)
        free(zappy->time);
    destroy_map(zappy->map);
    free(zappy);
    return 0;
}
