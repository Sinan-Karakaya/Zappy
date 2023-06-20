/*
** EPITECH PROJECT, 2023
** zappy_server
** File description:
** free_client_list
*/

#include "free.h"

static void free_commands(command_t *command)
{
    command_t *next_cmd = NULL;

    while (command) {
        next_cmd = command->next;
        if (command->args) {
            for (size_t i = 0; command->args[i]; i++)
                free(command->args[i]);
            free(command->args);
        }
        free(command);
        command = next_cmd;
    }
}

void destroy_client_info(client_info_t *info)
{
    if (info->lst_cmd) {
        free_commands(info->lst_cmd->first);
        free(info->lst_cmd);
    }
    free(info);
}

static void free_client_nodes(client_t *node)
{
    client_t *next = NULL;

    while (node) {
        next = node->next;
        if (node->info)
            destroy_client_info(node->info);
        free(node);
        node = next;
    }
}

void free_client_list(client_list_t *client_list)
{
    if (!client_list)
        return;
    free_client_nodes(client_list->first);
    free(client_list);
}
