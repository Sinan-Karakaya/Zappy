/*
** EPITECH PROJECT, 2023
** zappy_server
** File description:
** tests_eggs
*/

#include <criterion/criterion.h>
#include "utils.h"
#include "commands.h"

Test (ebo, ebo)
{
    my_zappy_t *zappy = malloc(sizeof(my_zappy_t));
    zappy->egg_list = (egg_list_t *)init_list();
    zappy->team_list = (team_list_t *)init_list();
    team_info_t *team = init_teams_info("Team1", 1);
    list_add_teams(zappy->team_list, team);

    client_info_t *info = init_clients_info(1, 10, 10);
    zappy->client_list = (client_list_t *)init_list();
    list_add_client(zappy->client_list, info);

    ebo(zappy, 1);
    destroy_client_in_list(zappy->client_list, 1);
    free(zappy->client_list);
    free(zappy->map);
    free(zappy);
}

Test (edi, edi)
{
    my_zappy_t *zappy = malloc(sizeof(my_zappy_t));
    zappy->egg_list = (egg_list_t *)init_list();
    zappy->team_list = (team_list_t *)init_list();
    team_info_t *team = init_teams_info("Team1", 1);
    list_add_teams(zappy->team_list, team);

    client_info_t *info = init_clients_info(1, 10, 10);
    zappy->client_list = (client_list_t *)init_list();
    list_add_client(zappy->client_list, info);

    edi(zappy, 1);
    destroy_client_in_list(zappy->client_list, 1);
    free(zappy->client_list);
    free(zappy->map);
    free(zappy);
}
