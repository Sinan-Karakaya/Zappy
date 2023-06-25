/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** check_alive
*/

#include "zappy_server.h"
#include "commands.h"

static int check_players_in_team(my_zappy_t *zappy, client_t *client)
{
    team_t *team = get_team_by_id(zappy->team_list, client->info->team_id);

    if (!zappy || !client || !team || team->info->actual_users == 0)
        return 84;
    if ((size_t)team->info->slots_available < team->info->max_slots)
        team->info->slots_available += 1;
    team->info->actual_users -= 1;
    return 0;
}

int check_alive(my_zappy_t *zappy, int fd)
{
    client_t *client = get_client_by_fd(zappy->client_list, fd);
    team_t *team = NULL;

    if (client->info->team_id <= TEAM_ID_GRAPHIC)
        return 0;
    if (client->info->player->is_alive == false) {
        team = get_team_by_id(zappy->team_list, client->info->team_id);
        pdi(zappy, fd);
        send_message(fd, DEATH);
        remove_id_in_list(zappy->map->tiles[client->info->player->y]
        [client->info->player->x].players, fd);
        if (team)
            remove_id_in_list(team->info->client_list, fd);
        check_players_in_team(zappy, client);
        destroy_client_in_list(zappy->client_list, fd);
        return 1;
    }
    return 0;
}

int disconnect_player(my_zappy_t *zappy, int fd)
{
    client_t *client = get_client_by_fd(zappy->client_list, fd);
    team_t *team = NULL;

    team = get_team_by_id(zappy->team_list, client->info->team_id);
    if (client->info->team_id > TEAM_ID_GRAPHIC)
        pdi(zappy, fd);
    remove_id_in_list(zappy->map->tiles[client->info->player->y]
    [client->info->player->x].players, fd);
    if (team)
        remove_id_in_list(team->info->client_list, fd);
    check_players_in_team(zappy, client);
    destroy_client_in_list(zappy->client_list, fd);
    return 0;
}
