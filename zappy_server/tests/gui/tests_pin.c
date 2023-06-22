/*
** EPITECH PROJECT, 2023
** zappy_server
** File description:
** tests_pin
*/

#include <criterion/criterion.h>
#include "utils.h"
#include "commands.h"

Test (pin, pin)
{
    char *args[] = {"mct", NULL};
    cmd_t *cmd = init_cmd(args);
    my_zappy_t *zappy = malloc(sizeof(my_zappy_t));
    zappy->map = init_map(10, 10);
    zappy->egg_list = (egg_list_t *)init_list();

    zappy->team_list = (team_list_t *)init_list();
    team_info_t *team = init_teams_info("Team1", 1);
    list_add_teams(zappy->team_list, team);

    client_info_t *info = init_clients_info(1, 10, 10);
    zappy->client_list = (client_list_t *)init_list();
    list_add_client(zappy->client_list, info);

    info->team_id = 0;
    zappy->client_list->first->info->player->direction = NORTH;
    zappy->client_list->last->info->player->direction = NORTH;

    zappy->client_list->first->info->player->x = 9;
    zappy->client_list->first->info->player->y = 9;

    cmd->args = malloc(sizeof(char *) * 3);
    cmd->args[0] = strdup("msz");
    cmd->args[1] = strdup("1");
    cmd->args[2] = NULL;
    pin(zappy, 1, cmd);

    destroy_client_in_list(zappy->client_list, 1);
    free(zappy->client_list);
    free(zappy->map);
    free(zappy);
    for (size_t i = 0; cmd->args[i]; i++)
        free(cmd->args[i]);
    free(cmd->args);
    free(cmd);
}
