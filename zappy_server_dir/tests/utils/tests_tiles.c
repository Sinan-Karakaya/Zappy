/*
** EPITECH PROJECT, 2023
** zappy_server
** File description:
** tests_tiles
*/

#include <criterion/criterion.h>
#include "utils.h"
#include "zappy_server.h"

Test (tiles, get_info_on_tile)
{
    map_t *map = init_map(10, 10);

    for (size_t i = 0; i < LENGHT_INVENTORY; i++)
        map->tiles[0][0].inventory[i] = 1;
    map->tiles[0][0].players = (id_list_t *)init_list();
    list_add_id(map->tiles[0][0].players, 1);
    cr_assert_str_eq(get_elements_on_tile(map, 0, 0),
        "player food linemate deraumere sibur mendiane phiras thystame ");
    remove_id_in_list(map->tiles[0][0].players, 1);
    free(map->tiles[0][0].players);
    for (ssize_t i = 0; i < map->y; i++)
        free(map->tiles[i]);
    free(map->tiles);
    free(map);
}
