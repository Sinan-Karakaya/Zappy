/*
** EPITECH PROJECT, 2023
** B-NWP-400-REN-4-1-myteams-axel.rohee
** File description:
** get_teams
*/

#include "team.h"
#include "zappy_server.h"

team_info_t *get_team_info(team_list_t *teams_list, char *team_uuid)
{
    char *uuid = NULL;

    for (team_t *tmp = teams_list->first; tmp != NULL; tmp = tmp->next) {
        uuid = uuid_to_char(tmp->info->team_uuid);
        if (strcmp(uuid, team_uuid) == 0) {
            free(uuid);
            return tmp->info;
        }
        free(uuid);
    }
    return NULL;
}

team_t *get_team_by_uuid(team_list_t *teams_list, char *team_uuid)
{
    char *uuid = NULL;

    for (team_t *tmp = teams_list->first; tmp != NULL; tmp = tmp->next) {
        uuid = uuid_to_char(tmp->info->team_uuid);
        if (strcmp(uuid, team_uuid) == 0) {
            free(uuid);
            return tmp;
        }
        free(uuid);
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

uuid_list_t *get_team_client_list(team_list_t *teams_list, char *team_uuid)
{
    char *uuid = NULL;

    for (team_t *tmp = teams_list->first; tmp != NULL; tmp = tmp->next) {
        uuid = uuid_to_char(tmp->info->team_uuid);
        if (strcmp(uuid, team_uuid) == 0) {
            free(uuid);
            return tmp->info->client_list;
        }
        free(uuid);
    }
    return NULL;
}
