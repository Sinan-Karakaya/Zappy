/*
** EPITECH PROJECT, 2023
** zappy_server
** File description:
** verify_incantation
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

static int check_players(my_zappy_t *zappy, client_t *client,
incantation_t my_incantation)
{
    client_t *tmp_client = NULL;
    size_t nb_players = 0;
    size_t same_lvl = 0;

    for (my_id_t *tmp = zappy->map->tiles[client->info->player->y]
    [client->info->player->x].players->first; tmp; tmp = tmp->next) {
        tmp_client = get_client_by_fd(zappy->client_list, tmp->id);
        if (!tmp_client)
            continue;
        if (tmp_client->info->player->lvl == client->info->player->lvl)
            same_lvl++;
        nb_players++;
    }
    if (nb_players < my_incantation.nb_players
    || same_lvl < my_incantation.nb_players)
        return 84;
    return 0;
}

static int check_resources(my_zappy_t *zappy, client_t *client,
incantation_t my_incantation)
{
    for (size_t i = 1; i < LENGHT_INVENTORY; i++) {
        if (zappy->map->tiles[client->info->player->y]
        [client->info->player->x].inventory[i] < my_incantation.ressources[i]) {
            return 84;
        }
    }
    return 0;
}

static int send_incantation_clients(my_zappy_t *zappy, client_t *client,
bool succeed)
{
    char *result = "";
    client_t *other = NULL;

    if (!client)
        return 84;
    if (succeed == true)
        asprintf(&result, "Elevation Underway\n");
    else
        asprintf(&result, "ko\n");
    for (my_id_t *tmp = zappy->map->tiles[client->info->player->y]
    [client->info->player->x].players->first; tmp; tmp = tmp->next) {
        other = get_client_by_fd(zappy->client_list, tmp->id);
        if (other->info->player->lvl == client->info->player->lvl
        && other->info->player->is_incanting == true) {
            other = get_client_by_fd(zappy->client_list, tmp->id);
            send_message(other->info->fd, result);
        }
    }
    free(result);
    return 0;
}

int verify_all_values_incantation(my_zappy_t *zappy, int fd)
{
    client_t *client = get_client_by_fd(zappy->client_list, fd);
    incantation_t my_incantation = incantations[client->info->player->lvl - 1];

    if (!client)
        return 84;
    if (check_players(zappy, client, my_incantation) == 84)
        return 84;
    if (check_resources(zappy, client, my_incantation) == 84)
        return 84;
    return 0;
}

int verify_incantation(my_zappy_t *zappy, int fd, cmd_t *cmd)
{
    client_t *client = get_client_by_fd(zappy->client_list, fd);

    pic(zappy, client, zappy->map->tiles[client->info->player->y]
    [client->info->player->x].players);
    lock_client(zappy, fd);
    if (verify_all_values_incantation(zappy, fd))
        send_incantation_clients(zappy, client, false);
    else {
        send_incantation_clients(zappy, client, true);
    }
    add_to_callback(zappy, fd, cmd);
    return 0;
}
