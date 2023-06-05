/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** map
*/

#include "map.h"

static void fill_map_part1(tiles_t **map, size_t x, size_t y)
{
    size_t pos_x = 0, pos_y = 0;

    for (size_t i = 0; i < x * y * FOOD_DENSITY; i++) {
        pos_x = rand() % x;
        pos_y = rand() % y;
        map[pos_x][pos_y].food++;
    } for (size_t i = 0; i < x * y * LINEMATE_DENSITY; i++) {
        pos_x = rand() % x;
        pos_y = rand() % y;
        map[pos_x][pos_y].linemate++;
    } for (size_t i = 0; i < x * y * DERAUMERE_DENSITY; i++) {
        pos_x = rand() % x;
        pos_y = rand() % y;
        map[pos_x][pos_y].deraumere++;
    } for (size_t i = 0; i < x * y * SIBUR_DENSITY; i++) {
        pos_x = rand() % x;
        pos_y = rand() % y;
        map[pos_x][pos_y].sibur++;
    }
}

static void fill_map_part2(tiles_t **map, size_t x, size_t y)
{
    size_t pos_x = 0, pos_y = 0;

    for (size_t i = 0; i < x * y * MENDIANE_DENSITY; i++) {
        pos_x = rand() % x;
        pos_y = rand() % y;
        map[pos_x][pos_y].mendiane++;
    } for (size_t i = 0; i < x * y * PHIRAS_DENSITY; i++) {
        pos_x = rand() % x;
        pos_y = rand() % y;
        map[pos_x][pos_y].phiras++;
    } for (size_t i = 0; i < x * y * THYSTAME_DENSITY; i++) {
        pos_x = rand() % x;
        pos_y = rand() % y;
        map[pos_x][pos_y].thystame++;
    }
}

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
    fill_map_part1(tile, x, y);
    fill_map_part2(tile, x, y);
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
