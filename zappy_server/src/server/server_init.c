/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** server_init
*/

#include "zappy_server.h"
#include <signal.h>
#include <unistd.h>

int init_teams(my_zappy_t *zappy, parsing_t *parsing)
{
    team_list_t *team_list = zappy->team_list;
    team_info_t *info = NULL;

    if (!team_list || !parsing)
        return 84;
    info = init_teams_info("GRAPHIC");
    if (info == NULL)
        return 84;
    list_add_teams(team_list, info);
    for (size_t i = 0; i < count_args(parsing->names); i++) {
        info = init_teams_info(parsing->names[i]);
        if (info == NULL)
            return 84;
        list_add_teams(team_list, info);
    }
    return 0;
}

my_zappy_t *init_zappy(parsing_t *parsing)
{
    my_zappy_t *zappy = malloc(sizeof(my_zappy_t));

    if (!parsing || !zappy)
        return NULL;
    zappy->server = create_socket(parsing->port);
    if (zappy->server == NULL)
        return NULL;
    zappy->team_list = (team_list_t *)init_list();
    if (init_teams(zappy, parsing) == 84)
        return NULL;
    zappy->client_list = (client_list_t *)init_list();
    return zappy;
}
