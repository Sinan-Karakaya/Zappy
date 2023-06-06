/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** pex
*/

#include "zappy_server.h"
#include "commands.h"

int pex(my_zappy_t *zappy, int fd)
{
    client_t *client = NULL;
    if (zappy == NULL)
        return 84;
    client = get_client_by_fd(zappy->client_list, fd);
    if (client == NULL)
        return 84;
    dprintf(fd, "pex %d\n", client->info->user_id);
    return 0;
}
