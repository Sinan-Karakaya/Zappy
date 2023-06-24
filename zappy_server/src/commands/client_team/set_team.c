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
    remove_id_in_list(zappy->map->tiles[client->info->player->y]
    [client->info->player->x].players, client->info->fd);
    if (cmd->args[0])
        free(cmd->args[0]);
    cmd->args[0] = strdup("msz");
    msz(zappy, client->info->fd, cmd);
    if (cmd->args[0])
        free(cmd->args[0]);
    cmd->args[0] = strdup("sgt");
    sgt(zappy, client->info->fd, cmd);
    if (cmd->args[0])
        free(cmd->args[0]);
    cmd->args[0] = strdup("mct");
    mct(zappy, client->info->fd, cmd);
    if (cmd->args[0])
        free(cmd->args[0]);
    cmd->args[0] = strdup("tna");
    tna(zappy, client->info->fd, cmd);
    return 0;
}

static int send_message_team(my_zappy_t *zappy, client_t *client,
team_t *team, cmd_t *cmd)
{
    char *msg = NULL;

    team->info->slots_available--;
    team->info->actual_users++;
    asprintf(&msg, "%ld\n", team->info->slots_available);
    add_cmd(cmd, msg);
    free(msg);
    asprintf(&msg, "%ld %ld\n", zappy->map->x, zappy->map->y);
    add_cmd(cmd, msg);
    pnw(zappy, client->info->fd);
    return 0;
}

static int send_message_egg(my_zappy_t *zappy, client_t *client,
team_t *team, cmd_t *cmd)
{
    char *msg = "";

    team->info->actual_users++;
    if (team->info->slots_available > 0)
        team->info->slots_available--;
    asprintf(&msg, "%ld\n", team->info->slots_available);
    add_cmd(cmd, msg);
    asprintf(&msg, "%ld %ld\n", zappy->map->x, zappy->map->y);
    add_cmd(cmd, msg);
    pnw(zappy, client->info->fd);
    return 1;
}

static int check_egg(my_zappy_t *zappy, int fd, cmd_t *cmd)
{
    client_t *client = get_client_by_fd(zappy->client_list, fd);
    team_t *team = get_team_by_name(zappy->team_list, cmd->args[0]);

    if (!client || !zappy || !team)
        return 84;
    for (egg_t *tmp = zappy->egg_list->first; tmp; tmp = tmp->next) {
        if (tmp->info->team_id == (size_t)team->info->team_id) {
            client->info->team_id = team->info->team_id;
            remove_id_in_list(zappy->map->tiles[client->info->player->y]
            [client->info->player->x].players, client->info->player->id);
            client->info->player->x = tmp->info->x;
            client->info->player->y = tmp->info->y;
            list_add_id(zappy->map->tiles[client->info->player->y]
            [client->info->player->x].players, client->info->player->id);
            ebo(zappy, tmp->info->id);
            team->info->nb_eggs--;
            destroy_egg(zappy->egg_list, tmp);
            return send_message_egg(zappy, client, team, cmd);
        }
    } return 0;
}

int set_team(my_zappy_t *zappy, int fd, cmd_t *cmd)
{
    client_t *client = get_client_by_fd(zappy->client_list, fd);
    team_t *team = NULL;

    if (!client || !zappy || count_args(cmd->args) != 1)
        return add_cmd(cmd, "ko\n");
    team = get_team_by_name(zappy->team_list, cmd->args[0]);
    if (!team)
        return add_cmd(cmd, "ko\n");
    if (check_egg(zappy, fd, cmd) == 1)
        return 0;
    if (team->info->slots_available <= 0)
        return add_cmd(cmd, "ko\n");
    client->info->team_id = team->info->team_id;
    if (team->info->team_id == 0)
        return send_message_graphic(zappy, client, cmd);
    return send_message_team(zappy, client, team, cmd);
}
