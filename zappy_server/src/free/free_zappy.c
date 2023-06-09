/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** free_all
*/

#include "free.h"
#include <stdlib.h>

//     my_time_t *time;

static void free_client_list(client_list_t *list)
{
    client_list_t *tmp = NULL;

    if (!list)
        return;
    while (list) {
        tmp = list;
        list = (client_list_t *)list->first->next;
        destroy_client_info(tmp->first->info);
        free(tmp);
    }
}

static void free_callback_list(list_t *list)
{
    list_t *tmp = NULL;

    if (!list)
        return;
    while (list) {
        tmp = list;
        list = (list_t *)list->first;
        free(tmp);
    }
    if (list)
        free(list);
}

static void destroy_map(map_t *map)
{
    if (!map)
        return;
    for (ssize_t i = 0; i < map->y; i++) {
        for (ssize_t j = 0; j < map->x; j++) {
            if (map->tiles[i][j].players->first)
                remove_id_in_list(map->tiles[i][j].players, map->tiles[i][j].players->first->id);
        }
        free(map->tiles[i]);
    }
    free(map->tiles);
    free(map);
}

size_t free_zappy(my_zappy_t *zappy)
{
    close(zappy->server->sockfd);
    free(zappy->server);
    free_client_list(zappy->client_list);
    destroy_struct_team(zappy->team_list->first);
    free_callback_list(zappy->callback_list);
    destroy_map(zappy->map);
    free(zappy);
    return 0;
}
