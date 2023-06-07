/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** check_alive
*/

#include "zappy_server.h"

int check_alive(my_zappy_t *zappy, int fd)
{
    client_t *client = get_client_by_fd(zappy->client_list, fd);

    if (client->info->team_id > TEAM_ID_GRAPHIC)
        return 0;
    if (client->info->player->is_alive == false) {
        send_message(fd, DEATH);
        destroy_client_in_list(zappy->client_list, fd);
        return 1;
    }
    return 0;
}
