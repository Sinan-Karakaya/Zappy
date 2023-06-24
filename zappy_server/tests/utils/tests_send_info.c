/*
** EPITECH PROJECT, 2023
** zappy_server
** File description:
** tests_send_info
*/

#include <criterion/criterion.h>
#include "commands.h"
#include "zappy_server.h"

Test (send_pos_to_graphics, send_pos_to_graphics)
{
    my_zappy_t *zappy = malloc(sizeof(my_zappy_t));
    zappy->map = init_map(10, 10);

    zappy->team_list = (team_list_t *)init_list();
    team_info_t *team = init_teams_info("Team1", 1);
    list_add_teams(zappy->team_list, team);
    zappy->team_list->first->info->client_list = (id_list_t *)init_list();

    client_info_t *info = init_clients_info(1, 10, 10);
    zappy->client_list = (client_list_t *)init_list();
    list_add_client(zappy->client_list, info);

    list_add_id(zappy->team_list->first->info->client_list, 1);
    info->team_id = 1;
    zappy->client_list->first->info->player->direction = NORTH;

    zappy->client_list->first->info->player->x = 9;
    zappy->client_list->first->info->player->y = 9;
    zappy->client_list->first->info->player->is_alive = false;

    send_pos_to_graphics(zappy, zappy->client_list->first);

    destroy_client_in_list(zappy->client_list, 1);
    free(zappy->client_list);
    free(zappy->map);
    free(zappy);
}

Test (send_inv_to_graphics, send_inv_to_graphics)
{
    my_zappy_t *zappy = malloc(sizeof(my_zappy_t));
    zappy->map = init_map(10, 10);

    zappy->team_list = (team_list_t *)init_list();
    team_info_t *team = init_teams_info("Team1", 1);
    list_add_teams(zappy->team_list, team);
    zappy->team_list->first->info->client_list = (id_list_t *)init_list();

    client_info_t *info = init_clients_info(1, 10, 10);
    zappy->client_list = (client_list_t *)init_list();
    list_add_client(zappy->client_list, info);

    list_add_id(zappy->team_list->first->info->client_list, 1);
    info->team_id = 1;
    zappy->client_list->first->info->player->direction = NORTH;

    zappy->client_list->first->info->player->x = 9;
    zappy->client_list->first->info->player->y = 9;
    zappy->client_list->first->info->player->is_alive = false;

    send_inventory_to_graphics(zappy, zappy->client_list->first);

    destroy_client_in_list(zappy->client_list, 1);
    free(zappy->client_list);
    free(zappy->map);
    free(zappy);
}
