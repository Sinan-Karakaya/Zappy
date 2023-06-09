/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** free_team
*/

#include "free.h"

static void destroy_team_info(team_info_t *info)
{
    if (!info)
        return;
    if (info->name)
        free(info->name);
    for (int i = 0; info->client_list[i].first; i++)
        remove_id_in_list(info->client_list, info->client_list->first->id);
    free(info);
}

void destroy_struct_team(team_t *team)
{
    team_t *tmp = NULL;

    if (!team)
        return;
    while (team->next) {
        tmp = team;
        team = team->next;
        if (tmp || tmp->info)
            destroy_team_info(tmp->info);
        free(tmp);
    }
    free(team);
}

void destroy_cmd(cmd_t *cmd)
{
    if (!cmd)
        return;
    if (cmd->args) {
        for (int i = 0; cmd->args[i]; i++)
            free(cmd->args[i]);
        free(cmd->args);
    } if (cmd->result) {
        for (int i = 0; cmd->result[i]; i++)
            free(cmd->result[i]);
        free(cmd->result);
    }
    free(cmd);
}
