/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** eject
*/

#include "zappy_server.h"
#include "commands.h"
#include "utils.h"

int verify_eject(my_zappy_t *zappy, int fd, cmd_t *cmd)
{
    add_to_callback(zappy, fd, cmd);
    return 0;
}

static size_t destroy_eggs(my_zappy_t *zappy, size_t x, size_t y)
{
    egg_t *egg = zappy->egg_list->first;
    egg_t *tmp = NULL;
    team_t *team = NULL;
    size_t count = 0;

    while (egg) {
        if (egg->info->x == x && egg->info->y == y) {
            team = get_team_by_id(zappy->team_list, egg->info->team_id);
            team->info->nb_eggs--;
            tmp = egg->next;
            edi(zappy, egg->info->id);
            destroy_egg(zappy->egg_list, egg);
            count++;
        } else
            tmp = egg->next;
        egg = tmp;
    }
    return count;
}

int eject(my_zappy_t *zappy, int fd, cmd_t *cmd)
{
    client_t *client = get_client_by_fd(zappy->client_list, fd);
    vector_t coordinates = real_coordinates(client, zappy->map);
    char *str = NULL;

    if (!zappy || !cmd || !cmd->args || !client || count_args(cmd->args) != 1)
        return send_message(fd, "ko\n");
    destroy_eggs(zappy, client->info->player->x, client->info->player->y);
    for (my_id_t *tmp = zappy->map->tiles[client->info->player->y]
    [client->info->player->x].players->first; tmp; tmp = tmp->next) {
        client_t *tmp_client = get_client_by_fd(zappy->client_list, tmp->id);
        if (tmp_client != client) {
            tmp_client->info->player->x = coordinates.x;
            tmp_client->info->player->y = coordinates.y;
            pex(zappy, tmp_client->info->fd), asprintf(&str, "eject: %ld\n",
            get_real_direction(tmp_client->info->player->direction,
            get_direction(client, tmp_client)));
            send_message(tmp_client->info->fd, str), free(str);
        }
    } return add_cmd(cmd, "ok\n");
}
