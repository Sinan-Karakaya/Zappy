/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** seg
*/

#include "zappy_server.h"
#include "commands.h"

int seg(my_zappy_t *zappy, int fd)
{
    char *result = NULL;
    client_t *client = NULL;
    team_t *team = NULL;

    if (zappy == NULL)
        return 0;
    client = get_client_by_fd(zappy->client_list, fd);
    team = get_team_by_id(zappy->team_list, client->info->team_id);
    asprintf(&result, "seg %s\n", team->info->name);
    send_message(fd, result);
    return 0;
}
