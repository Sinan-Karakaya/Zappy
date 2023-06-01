/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** map
*/

#include "map.h"

map_t *init_map(size_t x, size_t y)
{
    map_t *map = calloc(1, sizeof(map_t));

    if (!map)
        return NULL;
    map->x = x;
    map->y = y;
    for (size_t i = 0; i < LENGTH_DENSITY; i++)
        map->density[i] = 0;
    return (map);
}
