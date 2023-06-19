/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** destroy_teams
*/

#include "free.h"
#include <stdlib.h>

static size_t destroy_team_info(team_t *team)
{
    if (!team || !team->info)
        return 84;
    if (team->info->name)
        free(team->info->name);
    if (team->info->client_list)
        free(team->info->client_list);
    free(team->info);
    return 0;
}

size_t destroy_team(team_list_t *list, team_t *team)
{
    if (!team)
        return 0;
    destroy_team_info(team);
    if (list->first == team)
        list->first = team->next;
    if (list->last == team)
        list->last = team->prev;
    if (team->next)
        team->next->prev = team->prev;
    if (team->prev)
        team->prev->next = team->next;
    free(team);
    return 0;
}
