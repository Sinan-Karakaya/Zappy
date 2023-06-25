/*
** EPITECH PROJECT, 2023
** zappy_server
** File description:
** tests_tna
*/

#include <criterion/criterion.h>
#include "utils.h"
#include "commands.h"

Test (tna, tna)
{
    char *args[] = {"tna", NULL};
    cmd_t *cmd = init_cmd(args);
    my_zappy_t *zappy = malloc(sizeof(my_zappy_t));

    zappy->team_list = (team_list_t *)init_list();
    team_info_t *team = init_teams_info("Team1", 1);
    list_add_teams(zappy->team_list, team);
    team_info_t *team2 = init_teams_info("Team2", 1);
    list_add_teams(zappy->team_list, team2);

    client_info_t *info = init_clients_info(1, 10, 10);
    zappy->client_list = (client_list_t *)init_list();
    list_add_client(zappy->client_list, info);

    tna(zappy, 1, cmd);

    free(zappy);
    for (size_t i = 0; cmd->args[i]; i++)
        free(cmd->args[i]);
    free(cmd->args);
    free(cmd);
}
