/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** fork
*/

#include "zappy_server.h"
#include "commands.h"

int verify_fork(my_zappy_t *zappy, int fd, cmd_t *cmd)
{
    add_to_callback(zappy, fd, cmd);
    return 0;
}

static size_t get_max_id(egg_list_t *list)
{
    egg_t *egg = list->first;
    size_t max = 0;

    while (egg) {
        if (egg->info->id > max)
            max = egg->info->id;
        egg = egg->next;
    }
    return max + 1;
}

int fork_cmd(my_zappy_t *zappy, int fd, cmd_t *cmd)
{
    client_t *client = get_client_by_fd(zappy->client_list, fd);
    team_t *team = get_team_by_id(zappy->team_list, client->info->team_id);
    egg_info_t *egg_info = NULL;

    if (!zappy || !client || !team || count_args(cmd->args) != 1)
        return send_message(fd, "ko\n");
    egg_info = init_eggs_info(client->info->team_id, client->info->user_id,
    client->info->player->x, client->info->player->y);
    egg_info->id = get_max_id(zappy->egg_list);
    if (!egg_info)
        return send_message(fd, "ko\n");
    list_add_eggs(zappy->egg_list, egg_info);
    team->info->nb_eggs++;
    pfk(zappy, fd);
    enw(zappy, zappy->egg_list->last);
    send_message(fd, "ok\n");
    return 0;
}
