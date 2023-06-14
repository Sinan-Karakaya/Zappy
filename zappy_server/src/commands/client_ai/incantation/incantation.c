/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** incantation
*/

#include "zappy_server.h"
#include "commands.h"

static incantation_t incantations[] = {
    {2, 1, {0, 1, 0, 0, 0, 0, 0}},
    {3, 2, {0, 1, 1, 1, 0, 0, 0}},
    {4, 2, {0, 2, 0, 1, 0, 2, 0}},
    {5, 4, {0, 1, 1, 2, 0, 1, 0}},
    {6, 4, {0, 1, 2, 1, 3, 0, 0}},
    {7, 6, {0, 1, 2, 3, 0, 1, 0}},
    {8, 6, {0, 2, 2, 2, 2, 2, 1}},
    {0, 0, {0, 0, 0, 0, 0, 0, 0}}
};

int remove_resources_incantation(my_zappy_t *zappy, size_t x, size_t y, int lvl)
{
    incantation_t my_incantation = incantations[lvl - 1];

    for (size_t i = 1; i < LENGHT_INVENTORY; i++) {
        if (zappy->map->tiles[y][x].inventory[i] < my_incantation.ressources[i])
            return 84;
        zappy->map->tiles[y][x].inventory[i] -= my_incantation.ressources[i];
    }
    return 0;
}

static int send_incantation_clients(my_zappy_t *zappy, client_t *client,
bool succeed)
{
    char *res = "";
    client_t *other = NULL;

    if (!client)
        return 84;
    if (succeed == true)
        asprintf(&res, "Current level: %ld\n", client->info->player->lvl + 1);
    else
        asprintf(&res, "ko\n");
    for (my_id_t *tmp = zappy->map->tiles[client->info->player->y]
    [client->info->player->x].players->first; tmp; tmp = tmp->next) {
        other = get_client_by_fd(zappy->client_list, tmp->id);
        if (other->info->player->lvl == client->info->player->lvl
        && other->info->player->is_incanting == true) {
            other = get_client_by_fd(zappy->client_list, tmp->id);
            send_message(other->info->fd, res);
        }
    }
    free(res);
    return 0;
}

int incantation(my_zappy_t *zappy, int fd, NUSED cmd_t *cmd)
{
    client_t *client = get_client_by_fd(zappy->client_list, fd);

    if (verify_all_values_incantation(zappy, fd)) {
        pie(zappy, client, "0");
        send_incantation_clients(zappy, client, false);
        return unlock_clients(zappy, fd, false);
    }
    pie(zappy, client, "1");
    remove_resources_incantation(zappy, client->info->player->x,
    client->info->player->y, client->info->player->lvl);
    send_incantation_clients(zappy, client, true);
    unlock_clients(zappy, fd, true);
    return 0;
}
