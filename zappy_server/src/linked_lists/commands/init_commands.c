/*
** EPITECH PROJECT, 2023
** zappy_server
** File description:
** init_commands
*/

#include "clients.h"
#include "utils.h"

command_t *init_lst_commands(char **args)
{
    command_t *lst = calloc(1, sizeof(command_t));

    if (lst == NULL)
        return NULL;
    lst->args = dup_array(args);
    lst->next = NULL;
    lst->prev = NULL;
    return lst;
}
