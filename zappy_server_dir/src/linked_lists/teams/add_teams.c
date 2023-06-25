/*
** EPITECH PROJECT, 2023
** B-NWP-400-REN-4-1-myteams-axel.rohee
** File description:
** add_teams
*/

#include "team.h"
#include <stdlib.h>

static void list_add_at_back(team_list_t *team_list, team_info_t *team_info)
{
    team_t *tmp = NULL;

    if (team_info == NULL)
        return;
    tmp = team_list->first;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = calloc(1, sizeof(team_t));
    if (tmp->next == NULL)
        return;
    tmp->next->info = team_info;
    tmp->next->next = NULL;
    tmp->next->prev = tmp;
    team_list->last = tmp->next;
}

void list_add_teams(team_list_t *teams_list, team_info_t *team_info)
{
    team_t *tmp = NULL;

    if (team_info == NULL)
        return;
    if (teams_list->first == NULL) {
        tmp = calloc(1, sizeof(team_t));
        if (tmp == NULL)
            return;
        tmp->info = team_info;
        tmp->next = NULL;
        tmp->prev = NULL;
        teams_list->first = tmp;
        teams_list->last = tmp;
    } else {
        list_add_at_back(teams_list, team_info);
    }
}
