/*
** EPITECH PROJECT, 2023
** zappy_server
** File description:
** tests_direction
*/

#include <criterion/criterion.h>
#include "utils.h"

Test (direction_south, get_direction_north)
{
    client_t *client = malloc(sizeof(client_t));
    client_t *other = malloc(sizeof(client_t));

    client->info = init_clients_info(1, 10, 10);
    other->info = init_clients_info(1, 10, 10);

    other->info->player->direction = NORTH;
    client->info->player->direction = SOUTH;

    other->info->player->x = 10, other->info->player->y = 11;
    client->info->player->x = 10, client->info->player->y = 10;

    cr_assert(get_real_direction(client->info->player->direction,
            get_direction(client, other)) == S);

    free(client->info->player);
    free(other->info->player);
    free(client->info);
    free(other->info);
}

Test (direction_south, get_direction_northw)
{
    client_t *client = malloc(sizeof(client_t));
    client_t *other = malloc(sizeof(client_t));

    client->info = init_clients_info(1, 10, 10);
    other->info = init_clients_info(1, 10, 10);

    other->info->player->direction = NORTH;
    client->info->player->direction = SOUTH;

    other->info->player->x = 9, other->info->player->y = 11;
    client->info->player->x = 10, client->info->player->y = 10;

    cr_assert(get_real_direction(client->info->player->direction,
            get_direction(client, other)) == SE);

    free(client->info->player);
    free(other->info->player);
    free(client->info);
    free(other->info);
}

Test (direction_south, get_direction_west)
{
    client_t *client = malloc(sizeof(client_t));
    client_t *other = malloc(sizeof(client_t));

    client->info = init_clients_info(1, 10, 10);
    other->info = init_clients_info(1, 10, 10);

    other->info->player->direction = NORTH;
    client->info->player->direction = SOUTH;

    other->info->player->x = 9, other->info->player->y = 10;
    client->info->player->x = 10, client->info->player->y = 10;

    cr_assert(get_real_direction(client->info->player->direction,
            get_direction(client, other)) == E);

    free(client->info->player);
    free(other->info->player);
    free(client->info);
    free(other->info);
}

Test (direction_south, get_direction_southw)
{
    client_t *client = malloc(sizeof(client_t));
    client_t *other = malloc(sizeof(client_t));

    client->info = init_clients_info(1, 10, 10);
    other->info = init_clients_info(1, 10, 10);

    other->info->player->direction = NORTH;
    client->info->player->direction = SOUTH;

    other->info->player->x = 9, other->info->player->y = 9;
    client->info->player->x = 10, client->info->player->y = 10;

    cr_assert(get_real_direction(client->info->player->direction,
            get_direction(client, other)) == NE);

    free(client->info->player);
    free(other->info->player);
    free(client->info);
    free(other->info);
}

Test (direction_south, get_direction_south)
{
    client_t *client = malloc(sizeof(client_t));
    client_t *other = malloc(sizeof(client_t));

    client->info = init_clients_info(1, 10, 10);
    other->info = init_clients_info(1, 10, 10);

    other->info->player->direction = NORTH;
    client->info->player->direction = SOUTH;

    other->info->player->x = 10, other->info->player->y = 9;
    client->info->player->x = 10, client->info->player->y = 10;

    cr_assert(get_real_direction(client->info->player->direction,
            get_direction(client, other)) == N);

    free(client->info->player);
    free(other->info->player);
    free(client->info);
    free(other->info);
}

Test (direction_south, get_direction_southe)
{
    client_t *client = malloc(sizeof(client_t));
    client_t *other = malloc(sizeof(client_t));

    client->info = init_clients_info(1, 10, 10);
    other->info = init_clients_info(1, 10, 10);

    other->info->player->direction = NORTH;
    client->info->player->direction = SOUTH;

    other->info->player->x = 11, other->info->player->y = 11;
    client->info->player->x = 10, client->info->player->y = 10;

    cr_assert(get_real_direction(client->info->player->direction,
            get_direction(client, other)) == NW);

    free(client->info->player);
    free(other->info->player);
    free(client->info);
    free(other->info);
}

Test (direction_south, get_direction_east)
{
    client_t *client = malloc(sizeof(client_t));
    client_t *other = malloc(sizeof(client_t));

    client->info = init_clients_info(1, 10, 10);
    other->info = init_clients_info(1, 10, 10);

    other->info->player->direction = NORTH;
    client->info->player->direction = SOUTH;

    other->info->player->x = 11, other->info->player->y = 10;
    client->info->player->x = 10, client->info->player->y = 10;

    cr_assert(get_real_direction(client->info->player->direction,
            get_direction(client, other)) == W);

    free(client->info->player);
    free(other->info->player);
    free(client->info);
    free(other->info);
}


Test (direction_south, get_direction_northe)
{
    client_t *client = malloc(sizeof(client_t));
    client_t *other = malloc(sizeof(client_t));

    client->info = init_clients_info(1, 10, 10);
    other->info = init_clients_info(1, 10, 10);

    other->info->player->direction = NORTH;
    client->info->player->direction = SOUTH;

    other->info->player->x = 11, other->info->player->y = 9;
    client->info->player->x = 10, client->info->player->y = 10;

    cr_assert(get_real_direction(client->info->player->direction,
            get_direction(client, other)) == SW);

    free(client->info->player);
    free(other->info->player);
    free(client->info);
    free(other->info);
}
