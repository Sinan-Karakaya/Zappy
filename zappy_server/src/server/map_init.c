/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** map
*/

#include "map.h"

static tiles_t **init_tiles(size_t x, size_t y)
{
    tiles_t **tile = calloc(x, sizeof(tiles_t *));

    if (!tile)
        return NULL;
    for (size_t i = 0; i < x; i++) {
        tile[i] = calloc(y, sizeof(tiles_t));
        if (!tile[i])
            return NULL;
    }
    return tile;
}

map_t *init_map(size_t x, size_t y)
{
    map_t *map = calloc(1, sizeof(map_t));

    if (!map)
        return NULL;
    map->x = x;
    map->y = y;
    map->tiles = init_tiles(x, y);
    for (size_t i = 0; i < LENGTH_DENSITY; i++)
        map->density[i] = 0;
    return map;
}
