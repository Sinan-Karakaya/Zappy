/*
** EPITECH PROJECT, 2023
** zappy_server
** File description:
** add_commands
*/

#include "utils.h"
#include "clients.h"

static void list_add_at_back(lst_commands_t *command_list, command_t *command)
{
    command_t *tmp = NULL;

    if (command == NULL)
        return;
    tmp = command_list->first;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = calloc(1, sizeof(command_t));
    if (tmp->next == NULL)
        return;
    tmp->next->args = dup_array(command->args);
    tmp->next->next = NULL;
    tmp->next->prev = tmp;
    command_list->last = tmp->next;
}

void list_add_command(lst_commands_t *command_list, command_t *command)
{
    command_t *tmp = NULL;

    if (command == NULL)
        return;
    if (command_list->first == NULL) {
        tmp = calloc(1, sizeof(command_t));
        if (tmp == NULL)
            return;
        tmp->args = dup_array(command->args);
        tmp->next = NULL;
        tmp->prev = NULL;
        command_list->first = tmp;
        command_list->last = tmp;
    } else {
        list_add_at_back(command_list, command);
    }
}
