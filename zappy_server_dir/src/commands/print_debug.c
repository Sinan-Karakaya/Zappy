/*
** EPITECH PROJECT, 2023
** zappy_server
** File description:
** print_debug
*/

#include <stdio.h>
#include "zappy_server.h"

int print_debug(my_zappy_t *zappy, client_t *client, char **cmd)
{
    team_t *team = NULL;

    if (client == NULL || cmd == NULL)
        return 84;
    team = get_team_by_id(zappy->team_list, client->info->team_id);
    if (team) {
        if (team->info->team_id == TEAM_ID_GRAPHIC)
            printf("%s: %s %s: %s %d: ", SERVER_YELLOW, TEAM_BLUE,
            TEAM_GRAPHIC, CLIENT_RED, client->info->fd);
        else
            printf("%s: %s \033[0;35m[%s]\033[0m: %s %d: ", SERVER_YELLOW,
            TEAM_BLUE, team->info->name, CLIENT_RED, client->info->fd);
    } else
        printf("%s: %s %s:\t%s %d: ", SERVER_YELLOW, TEAM_BLUE, "N/A",
        CLIENT_RED, client->info->fd);
    for (size_t i = 0; cmd[i] != NULL; i++)
        printf("%s ", cmd[i]);
    printf("\n");
    return 0;
}
