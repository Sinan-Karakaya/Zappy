/*
** EPITECH PROJECT, 2023
** zappy_server
** File description:
** tests_check_victory
*/

#include <criterion/criterion.h>
#include "utils.h"
#include "commands.h"
#include "zappy_server.h"

Test (Check_victory, Check_victory)
{
    char *args[] = {"Eject", NULL};
    cmd_t *cmd = init_cmd(args);
    my_zappy_t *zappy = malloc(sizeof(my_zappy_t));
    zappy->map = init_map(10, 10);

    zappy->team_list = (team_list_t *)init_list();
    team_info_t *team = init_teams_info("Team1", 1);
    list_add_teams(zappy->team_list, team);
    zappy->team_list->first->info->client_list = (id_list_t *)init_list();

    client_info_t *info = init_clients_info(1, 10, 10);
    zappy->client_list = (client_list_t *)init_list();
    list_add_client(zappy->client_list, info);

    for (int i = 0; i < 10; i++)
        list_add_id(zappy->team_list->first->info->client_list, 1);
    info->team_id = 1;
    info->player->lvl = 8;
    zappy->client_list->first->info->player->direction = NORTH;

    zappy->client_list->first->info->player->x = 9;
    zappy->client_list->first->info->player->y = 9;
    zappy->client_list->first->info->player->is_alive = false;

    cr_assert_eq(check_victory(zappy), true);
    destroy_client_in_list(zappy->client_list, 1);
    free(zappy->client_list);
    free(zappy->map);
    free(zappy);
    free(cmd->args);
    free(cmd);
}

Test (Check_victory, Check_no_victory)
{
    char *args[] = {"Eject", NULL};
    cmd_t *cmd = init_cmd(args);
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
    info->player->lvl = 8;
    zappy->client_list->first->info->player->direction = NORTH;

    zappy->client_list->first->info->player->x = 9;
    zappy->client_list->first->info->player->y = 9;
    zappy->client_list->first->info->player->is_alive = false;

    cr_assert_eq(check_victory(zappy), false);
    destroy_client_in_list(zappy->client_list, 1);
    free(zappy->client_list);
    free(zappy->map);
    free(zappy);
    free(cmd->args);
    free(cmd);
}