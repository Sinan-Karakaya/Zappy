/*
** EPITECH PROJECT, 2023
** B-NWP-400-REN-4-1-myteams-axel.rohee
** File description:
** init_list
*/

#include "zappy_server.h"

list_t *init_list(void)
{
    list_t *my_value = malloc(sizeof(list_t));

    if (!my_value)
        return NULL;
    my_value->first = NULL;
    my_value->last = NULL;
    return my_value;
}
