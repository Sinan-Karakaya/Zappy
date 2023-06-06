/*
** EPITECH PROJECT, 2023
** B-NWP-400-REN-4-1-myteams-axel.rohee
** File description:
** get_teams
*/

#include "team.h"
#include "zappy_server.h"

team_info_t *get_team_info(team_list_t *teams_list, int team_id)
{

    for (team_t *tmp = teams_list->first; tmp != NULL; tmp = tmp->next) {
        if (tmp->info->team_id == team_id) {
            return tmp->info;
        }
    }
    return NULL;
}

team_t *get_team_by_id(team_list_t *teams_list, int team_id)
{
    for (team_t *tmp = teams_list->first; tmp != NULL; tmp = tmp->next) {
        if (tmp->info->team_id == team_id) {
            return tmp;
        }
    }
    return NULL;
}

team_t *get_team_by_name(team_list_t *teams_list, char *name)
{
    for (team_t *tmp = teams_list->first; tmp != NULL; tmp = tmp->next) {
        if (strcmp(tmp->info->name, name) == 0)
            return tmp;
    }
    return NULL;
}

id_list_t *get_team_client_list(team_list_t *teams_list, int team_id)
{
    for (team_t *tmp = teams_list->first; tmp != NULL; tmp = tmp->next) {
        if (tmp->info->team_id == team_id) {
            return tmp->info->client_list;
        }
    }
    return NULL;
}
