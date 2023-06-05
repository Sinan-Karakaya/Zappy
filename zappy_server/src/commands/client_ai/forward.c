/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** forward
*/

#include "zappy_server.h"
#include "utils.h"
#include "commands.h"

static vector_t vertical_movement(client_t *client, map_t *map, vector_t coords)
{
    if (client->info->player->direction == NORTH) {
        coords.y -= 1;
        if (coords.y < 0)
            coords.y = map->y - 1;
        if (coords.y > map->y - 1)
            coords.y = 0;
    } else if (client->info->player->direction == SOUTH) {
        coords.y += 1;
        if (coords.y < 0)
            coords.y = map->y - 1;
        if (coords.y > map->y - 1)
            coords.y = 0;
    }
    return coords;
}

static vector_t horiz_movement(client_t *client, map_t *map, vector_t coords)
{
    if (client->info->player->direction == NORTH) {
        coords.x -= 1;
        if (coords.x < 0)
            coords.x = map->x - 1;
        if (coords.x > map->x - 1)
            coords.x = 0;
    } else if (client->info->player->direction == SOUTH) {
        coords.x += 1;
        if (coords.x < 0)
            coords.x = map->x - 1;
        if (coords.x > map->x - 1)
            coords.x = 0;
    }
    return coords;
}

static vector_t real_coordinates(client_t *client, map_t *map)
{
    vector_t coordinates = {client->info->player->x, client->info->player->y};

    if (client->info->player->direction == EAST
    || client->info->player->direction == WEST)
        coordinates = horiz_movement(client, map, coordinates);
    else
        coordinates = vertical_movement(client, map, coordinates);
    return coordinates;
}

int forward(my_zappy_t *zappy, int fd, char **args)
{
    client_t *client = get_client_by_fd(zappy->client_list, fd);
    vector_t coordinates = real_coordinates(client, zappy->map);

    if (!zappy || !client)
        return 84;
    return 0;
}
