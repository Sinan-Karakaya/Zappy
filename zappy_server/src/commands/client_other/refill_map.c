/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** refill_map
*/

#include "map.h"

static void fill_map_part1(tiles_t **map, size_t x, size_t y)
{
    size_t pos_x = 0, pos_y = 0;

    for (size_t i = 0; i < x * y * FOOD_DENSITY; i++) {
        pos_x = rand() % x;
        pos_y = rand() % y;
        map[pos_x][pos_y].inventory[FOOD]++;
    } for (size_t i = 0; i < x * y * LINEMATE_DENSITY; i++) {
        pos_x = rand() % x;
        pos_y = rand() % y;
        map[pos_x][pos_y].inventory[LINEMATE]++;
    } for (size_t i = 0; i < x * y * DERAUMERE_DENSITY; i++) {
        pos_x = rand() % x;
        pos_y = rand() % y;
        map[pos_x][pos_y].inventory[DERAUMERE]++;
    } for (size_t i = 0; i < x * y * SIBUR_DENSITY; i++) {
        pos_x = rand() % x;
        pos_y = rand() % y;
        map[pos_x][pos_y].inventory[SIBUR]++;
    }
}

static void fill_map_part2(tiles_t **map, size_t x, size_t y)
{
    size_t pos_x = 0, pos_y = 0;

    for (size_t i = 0; i < x * y * MENDIANE_DENSITY; i++) {
        pos_x = rand() % x;
        pos_y = rand() % y;
        map[pos_x][pos_y].inventory[MENDIANE]++;
    } for (size_t i = 0; i < x * y * PHIRAS_DENSITY; i++) {
        pos_x = rand() % x;
        pos_y = rand() % y;
        map[pos_x][pos_y].inventory[PHIRAS]++;
    } for (size_t i = 0; i < x * y * THYSTAME_DENSITY; i++) {
        pos_x = rand() % x;
        pos_y = rand() % y;
        map[pos_x][pos_y].inventory[THYSTAME]++;
    }
}

void refill_map(map_t *map)
{
    fill_map_part1(map->tiles, map->x, map->y);
    fill_map_part2(map->tiles, map->x, map->y);
}
