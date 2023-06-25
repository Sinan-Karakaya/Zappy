/*
** EPITECH PROJECT, 2023
** zappy_server
** File description:
** free_map
*/

#include "free.h"

void destroy_map(map_t *map)
{
    if (!map)
        return;
    if (!map->tiles) {
        free(map);
        return;
    } for (ssize_t i = 0; i < map->y; i++) {
        if (!map->tiles[i])
            continue;
        for (ssize_t j = 0; j < map->x; j++)
            free(map->tiles[i][j].players);
        free(map->tiles[i]);
    }
    free(map->tiles);
    free(map);
}
