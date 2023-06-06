/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** set_team
*/

#include "zappy_server.h"

//msz 10 10
//sgt 100
//bct all map
//tna all team
static int send_message_graphic(NUSED my_zappy_t *zappy, client_t *client)
{
    send_message(client->info->fd, "Not Available Yet :(\n");
    return 0;
}

static int send_message_team(my_zappy_t *zappy, client_t *client, team_t *team)
{
    char *msg = "";

    team->info->slots_available--;
    asprintf(&msg, "%ld\n", team->info->slots_available);
    send_message(client->info->fd, msg);
    asprintf(&msg, "%ld %ld\n", zappy->map->x, zappy->map->y);
    send_message(client->info->fd, msg);
    return 0;
}

int set_team(my_zappy_t *zappy, int fd, char **args)
{
    client_t *client = get_client_by_fd(zappy->client_list, fd);
    team_t *team = NULL;

    if (!client || !zappy || count_args(args) != 1)
        return send_message(fd, "ko\n");
    team = get_team_by_name(zappy->team_list, args[0]);
    if (!team || team->info->slots_available <= 0)
        return send_message(fd, "ko\n");
    client->info->team_id = team->info->team_id;
    if (team->info->team_id == 0)
        return send_message_graphic(zappy, client);
    return send_message_team(zappy, client, team);
}
