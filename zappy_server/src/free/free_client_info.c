/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** free_client_info
*/

#include "zappy_server.h"
#include "free.h"

void destroy_client_info(client_info_t *client)
{
    if (!client)
        return;
    if (client->player)
        free(client->player);
    free(client);
}
