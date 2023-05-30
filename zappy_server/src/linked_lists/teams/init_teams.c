/*
** EPITECH PROJECT, 2023
** B-NWP-400-REN-4-1-myteams-axel.rohee
** File description:
** init_zappy
*/

#include "team.h"
#include "zappy_server.h"

team_info_t *init_teams_info(char *name, char *description)
{
    team_info_t *info = malloc(sizeof(team_info_t));

    if (info == NULL)
        return NULL;
    info->description = strdup(description);
    info->name = strdup(name);
    uuid_generate_random(info->team_uuid);
    info->client_list = (uuid_list_t *)init_list();
    return info;
}
