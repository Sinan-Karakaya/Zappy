/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** server_init
*/

#include "zappy_server.h"
#include "free.h"
#include "utils.h"
#include <signal.h>
#include <unistd.h>

int init_teams(my_zappy_t *zappy, parsing_t *parsing)
{
    team_list_t *team_list = zappy->team_list;
    team_info_t *info = NULL;

    if (!team_list || !parsing)
        return 84;
    info = init_teams_info("GRAPHIC", 0);
    info->printable = false;
    if (info == NULL)
        return 84;
    list_add_teams(team_list, info);
    for (size_t i = 0; i < count_args(parsing->names); i++) {
        info = init_teams_info(parsing->names[i], i + 1);
        if (info == NULL)
            return 84;
        info->slots_available = parsing->clients_nb;
        list_add_teams(team_list, info);
    }
    return 0;
}

static int init_zappy_bis(my_zappy_t *zappy, parsing_t *parsing)
{
    if (!zappy->server || !parsing)
        return 84;
    zappy->map = init_map(parsing->width, parsing->height);
    if (!zappy->map)
        return 84;
    zappy->time = init_time(parsing->freq);
    if (!zappy->time)
        return 84;
    zappy->callback_list = init_list();
    if (!zappy->callback_list)
        return 84;
    return 0;
}

my_zappy_t *init_zappy(parsing_t *parsing)
{
    my_zappy_t *zappy = calloc(1, sizeof(my_zappy_t));

    if (!parsing || !zappy)
        return NULL;
    zappy->server = create_socket(parsing->port);
    if (zappy->server == NULL)
        return NULL;
    zappy->team_list = (team_list_t *)init_list();
    if (init_teams(zappy, parsing) == 84)
        return NULL;
    zappy->client_list = (client_list_t *)init_list();
    if (!zappy->client_list)
        return NULL;
    if (init_zappy_bis(zappy, parsing) == 84)
        return NULL;
    zappy->frequency = parsing->freq;
    free_parsing(parsing);
    return zappy;
}
