/*
** EPITECH PROJECT, 2023
** zappy_server
** File description:
** tests_connect_nbr
*/

#include <criterion/criterion.h>
#include "utils.h"
#include "commands.h"

Test (connect_number, connect_nbr)
{
    cmd_t *cmd = malloc(sizeof(cmd_t));
    my_zappy_t *zappy = malloc(sizeof(my_zappy_t));
    client_info_t *info = init_clients_info(1, 10, 10);
    zappy->map = init_map(10, 10);
    team_info_t *team = init_teams_info("Team1", 1);

    zappy->team_list = (team_list_t *)init_list();
    list_add_teams(zappy->team_list, team);

    zappy->client_list = (client_list_t *)init_list();
    list_add_client(zappy->client_list, info);

    zappy->client_list->first->info->player->direction = NORTH;
    zappy->client_list->first->info->team_id = 1;

    zappy->client_list->first->info->player->x = 9;
    zappy->client_list->first->info->player->y = 9;

    cmd->args = malloc(sizeof(char *) * 2);
    cmd->args[0] = strdup("connect_nbr");
    cmd->args[1] = NULL;

    connect_nbr(zappy, 1, cmd);
    destroy_client_in_list(zappy->client_list, 1);
    destroy_team(zappy->team_list, zappy->team_list->first);
    free(zappy->team_list);
    free(zappy->client_list);
    free(zappy->map);
    free(zappy);
    free(cmd->args);
    free(cmd);
}