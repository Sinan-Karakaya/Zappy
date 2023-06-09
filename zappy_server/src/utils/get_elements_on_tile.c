/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** get_elements_on_tile
*/

#include "zappy_server.h"
#include "commands.h"

char *get_elements_on_tile(map_t *map, size_t x, size_t y)
{
    char *result = "";

    for (my_id_t *i = map->tiles[y][x].players->first; i; i = i->next)
        asprintf(&result, "%splayer ", result);
    for (size_t i = 0; i < LENGHT_INVENTORY; i++) {
        for (size_t j = 0; j < map->tiles[y][x].inventory[i]; j++)
            asprintf(&result, "%s%s ", result, get_item_name(i));
    }
    return result;
}
