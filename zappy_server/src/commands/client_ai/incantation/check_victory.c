/*
** EPITECH PROJECT, 2023
** zappy_server
** File description:
** check_victory
*/

#include "zappy_server.h"
#include "commands.h"

static bool check_victory_team(my_zappy_t *zappy, team_t *team)
{
    size_t nb_players = 0;
    client_t *client = NULL;

    for (my_id_t *tmp = team->info->client_list->first; tmp; tmp = tmp->next) {
        client = get_client_by_fd(zappy->client_list, tmp->id);
        if (!client)
            continue;
        if (client->info->player->lvl == 8)
            nb_players++;
    }
    if (nb_players >= 6) {
        seg(zappy, team->info->name);
        return true;
    }
    return false;
}

int check_victory(my_zappy_t *zappy)
{
    for (team_t *tmp = zappy->team_list->first; tmp; tmp = tmp->next) {
        if (check_victory_team(zappy, tmp))
            return true;
    }
    return false;
}