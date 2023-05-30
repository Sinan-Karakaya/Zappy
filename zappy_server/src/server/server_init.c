/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** server_init
*/

#include "zappy_server.h"
#include <signal.h>
#include <unistd.h>

my_zappy_t *init_zappy(parsing_t *parsing)
{
    my_zappy_t *zappy = malloc(sizeof(my_zappy_t));

    if (!parsing || !zappy)
        return NULL;
    zappy->server = create_socket(parsing->port);
    if (zappy->server == NULL)
        return NULL;
    zappy->team_list = (team_list_t *)init_list();
    zappy->client_list = (client_list_t *)init_list();
    return zappy;
}
