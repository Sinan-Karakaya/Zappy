/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** connect_nbr
*/

#include "zappy_server.h"
#include "commands.h"

int verify_connect_nbr(my_zappy_t *zappy, int fd, NUSED cmd_t *cmd)
{
    add_to_callback(zappy, fd, cmd);
    return 0;
}

int connect_nbr(my_zappy_t *zappy, int fd, NUSED cmd_t *cmd)
{
    client_t *client = get_client_by_fd(zappy->client_list, fd);
    team_t *team = get_team_by_id(zappy->team_list, client->info->team_id);
    char *msg = "";

    if (!zappy || !client || !team)
        return 84;
    asprintf(&msg, "%ld\n", team->info->slots_available);
    send_message(fd, msg);
    return 0;
}
