/*
** EPITECH PROJECT, 2023
** zappy_server
** File description:
** get_direction
*/

#include "zappy_server.h"
#include "utils.h"

size_t get_direction(client_t *client, client_t *other)
{
    int delta_x = other->info->player->x - client->info->player->x;
    int delta_y = other->info->player->y - client->info->player->y;

    if (delta_x > 0 && delta_y > 0)
        return NE;
    if (delta_x > 0 && delta_y < 0)
        return SE;
    if (delta_x < 0 && delta_y > 0)
        return NW;
    if (delta_x < 0 && delta_y < 0)
        return SW;
    if (delta_x > 0 && delta_y == 0)
        return E;
    if (delta_x < 0 && delta_y == 0)
        return W;
    if (delta_x == 0 && delta_y > 0)
        return N;
    if (delta_x == 0 && delta_y < 0)
        return S;
    return SAME;
}

static size_t get_direction_west(size_t direction)
{
    if (direction == N)
        return E;
    if (direction == NW)
        return NE;
    if (direction == W)
        return N;
    if (direction == SW)
        return NW;
    if (direction == S)
        return W;
    if (direction == SE)
        return SW;
    if (direction == E)
        return S;
    if (direction == NE)
        return SE;
    return 0;
}

static size_t get_direction_east(size_t direction)
{
    if (direction == N)
        return W;
    if (direction == NW)
        return SW;
    if (direction == W)
        return S;
    if (direction == SW)
        return SE;
    if (direction == S)
        return E;
    if (direction == SE)
        return NE;
    if (direction == E)
        return N;
    if (direction == NE)
        return NW;
    return 0;
}

static size_t get_direction_south(size_t direction)
{
    if (direction == N)
        return S;
    if (direction == NW)
        return SE;
    if (direction == W)
        return E;
    if (direction == SW)
        return NE;
    if (direction == S)
        return N;
    if (direction == SE)
        return NW;
    if (direction == E)
        return W;
    if (direction == NE)
        return SW;
    return 0;
}

size_t get_real_direction(size_t orientation, size_t direction)
{
    if (orientation == NORTH)
        return direction;
    if (orientation == WEST)
        return get_direction_west(direction);
    if (orientation == EAST)
        return get_direction_east(direction);
    return get_direction_south(direction);
}
