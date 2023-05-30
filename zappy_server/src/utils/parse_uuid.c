/*
** EPITECH PROJECT, 2023
** B-NWP-400-REN-4-1-myteams-axel.rohee
** File description:
** parse_uuid
*/

#include "zappy_server.h"

char *uuid_to_char(uuid_t uuid)
{
    char *str = malloc(sizeof(char) * 37);

    if (str == NULL)
        return NULL;
    uuid_unparse(uuid, str);
    return str;
}
