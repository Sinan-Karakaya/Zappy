/*
** EPITECH PROJECT, 2023
** zappy_server
** File description:
** print_debug
*/

#include <stdio.h>
#include "zappy_server.h"

int print_debug(client_t *client, char **cmd)
{
    if (client == NULL || cmd == NULL)
        return 84;
    printf("%s: Client %d: ", SERVER_YELLOW, client->info->fd);
    for (size_t i = 0; cmd[i] != NULL; i++)
        printf("%s ", cmd[i]);
    printf("\n");
    return 0;
}
