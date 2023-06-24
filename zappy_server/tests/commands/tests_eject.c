/*
** EPITECH PROJECT, 2023
** zappy_server
** File description:
** tests_eject
*/

#include <criterion/criterion.h>
#include "utils.h"
#include "commands.h"

Test (Eject, Eject)
{
    char *args[] = {"Eject", NULL};
    cmd_t *cmd = init_cmd(args);
    my_zappy_t *zappy = malloc(sizeof(my_zappy_t));
    zappy->map = init_map(10, 10);
    zappy->egg_list = (egg_list_t *)init_list();

    zappy->team_list = (team_list_t *)init_list();
    team_info_t *team = init_teams_info("Team1", 1);
    list_add_teams(zappy->team_list, team);

    client_info_t *info = init_clients_info(1, 10, 10);
    client_info_t *info_bis = init_clients_info(2, 10, 10);
    zappy->client_list = (client_list_t *)init_list();
    list_add_client(zappy->client_list, info);
    list_add_client(zappy->client_list, info_bis);

    info->team_id = 1;
    info_bis->team_id = 1;
    zappy->client_list->first->info->player->direction = NORTH;
    zappy->client_list->last->info->player->direction = NORTH;

    zappy->client_list->first->info->player->x = 9;
    zappy->client_list->first->info->player->y = 9;
    zappy->client_list->last->info->player->x = 9;
    zappy->client_list->last->info->player->y = 9;

    cmd->args = malloc(sizeof(char *) * 2);
    cmd->args[0] = strdup("Eject");
    cmd->args[1] = NULL;

    fork_cmd(zappy, 1, cmd);
    forward(zappy, 1, cmd);
    forward(zappy, 2, cmd);
    eject(zappy, 1, cmd);
    destroy_client_in_list(zappy->client_list, 1);
    destroy_client_in_list(zappy->client_list, 1);
    free(zappy->client_list);
    free(zappy->map);
    free(zappy);
    free(cmd->args);
    free(cmd);
}
