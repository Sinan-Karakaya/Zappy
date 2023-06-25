/*
** EPITECH PROJECT, 2023
** zappy_server
** File description:
** destroy_command
*/

#include "clients.h"

static size_t destroy_command(command_t *command)
{
    if (!command)
        return 0;
    if (command->args)
        for (size_t i = 0; command->args[i] != NULL; i++)
            free(command->args[i]);
    if (command->args)
        free(command->args);
    return 0;
}

size_t destroy_command_list(lst_commands_t *list)
{
    command_t *tmp = NULL;

    if (!list)
        return 0;
    while (list->first) {
        tmp = list->first;
        list->first = list->first->next;
        destroy_command(tmp);
        free(tmp);
    }
    return 0;
}

size_t pop_front_cmd(lst_commands_t *list)
{
    command_t *tmp = NULL;

    if (!list || !list->first)
        return 0;
    tmp = list->first;
    list->first = list->first->next;
    destroy_command(tmp);
    free(tmp);
    return 0;
}
