/*
** EPITECH PROJECT, 2023
** zappy_server
** File description:
** tests_time
*/

#include <criterion/criterion.h>
#include "utils.h"
#include "commands.h"

Test (time, time)
{
    my_zappy_t *zappy = malloc(sizeof(my_zappy_t));
    client_info_t *info = init_clients_info(1, 10, 10);
    zappy->map = init_map(10, 10);
    zappy->callback_list = init_list();
    zappy->time = init_time(10000);
    my_time_t *time = init_time(10000);

    zappy->client_list = (client_list_t *)init_list();
    list_add_client(zappy->client_list, info);

    zappy->client_list->first->info->player->direction = NORTH;

    zappy->client_list->first->info->player->x = 9;
    zappy->client_list->first->info->player->y = 9;

    time->time_per_tick = 0;
    get_actual_time(zappy, time);
    destroy_client_in_list(zappy->client_list, 1);
    destroy_callback((callback_list_t *)zappy->callback_list,
    zappy->callback_list->first);
    free(zappy->callback_list);
    free(zappy->client_list);
    free(zappy->map);
    free(zappy->time);
    free(zappy);
}

