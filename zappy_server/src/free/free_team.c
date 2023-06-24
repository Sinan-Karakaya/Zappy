/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** free_team
*/

#include "free.h"

void free_team_list(team_list_t *team_list)
{
    team_t *current = NULL;
    team_t *next = NULL;

    if (!team_list)
        return;
    current = team_list->first;
    while (current) {
        next = current->next;
        if (current->info) {
            free(current->info->name);
            free(current->info->client_list);
            free(current->info);
        }
        free(current);
        current = next;
    }
    free(team_list);
}

void destroy_struct_team(team_t *team)
{
    if (!team)
        return;
    if (team->info) {
        free(team->info->name);
        free(team->info->client_list);
        free(team->info);
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
