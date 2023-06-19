/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** pex
*/

#include "free.h"
#include "commands.h"

int pex(my_zappy_t *zappy, int fd)
{
    client_t *client = NULL;
    char *str = "";

    if (zappy == NULL)
        return 84;
    client = get_client_by_fd(zappy->client_list, fd);
    if (client == NULL)
        return 84;
    asprintf(&str, "pex %d\n", client->info->user_id);
    send_to_graphics(zappy, str);
    destroy_client_info(client->info);
    free(str);
    free(client);
    return 0;
}
