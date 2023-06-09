/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** set_team
*/

#include "zappy_server.h"
#include "commands.h"

static int send_message_graphic(NUSED my_zappy_t *zappy,
    client_t *client, cmd_t *cmd)
{
    cmd->args[0] = strdup("msz");
    msz(zappy, client->info->fd, cmd);
    cmd->args[0] = strdup("sgt");
    sgt(zappy, client->info->fd, cmd);
    cmd->args[0] = strdup("mct");
    mct(zappy, client->info->fd, cmd);
    cmd->args[0] = strdup("tna");
    tna(zappy, client->info->fd, cmd);
    return 0;
}

static int send_message_team(my_zappy_t *zappy, team_t *team, cmd_t *cmd)
{
    char *msg = "";

    team->info->slots_available--;
    asprintf(&msg, "%ld\n", team->info->slots_available);
    add_cmd(cmd, msg);
    asprintf(&msg, "%ld %ld\n", zappy->map->x, zappy->map->y);
    add_cmd(cmd, msg);
    return 0;
}

int set_team(my_zappy_t *zappy, int fd, cmd_t *cmd)
{
    client_t *client = get_client_by_fd(zappy->client_list, fd);
    team_t *team = NULL;

    if (!client || !zappy || count_args(cmd->args) != 1)
        return add_cmd(cmd, "ko\n");
    team = get_team_by_name(zappy->team_list, cmd->args[0]);
    if (!team || team->info->slots_available <= 0)
        return add_cmd(cmd, "ko\n");
    client->info->team_id = team->info->team_id;
    if (team->info->team_id == 0)
        return send_message_graphic(zappy, client, cmd);
    return send_message_team(zappy, team, cmd);
}
