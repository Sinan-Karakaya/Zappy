/*
** EPITECH PROJECT, 2023
** B-NWP-400-REN-4-1-myteams-axel.rohee
** File description:
** init_zappy
*/

#include "team.h"
#include "zappy_server.h"

team_info_t *init_teams_info(char *name, int team_id)
{
    team_info_t *info = calloc(1, sizeof(team_info_t));

    if (info == NULL)
        return NULL;
    info->name = strdup(name);
    info->team_id = team_id;
    info->client_list = (id_list_t *)init_list();
    info->nb_clients = 0;
    info->printable = true;
    info->slots_available = 3;
    return info;
}
