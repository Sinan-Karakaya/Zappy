/*
** EPITECH PROJECT, 2023
** *
** File description:
** tests_forward
*/


#include <criterion/criterion.h>
#include "utils.h"
#include "commands.h"

Test (Forward, Forward)
{
    cmd_t *cmd = malloc(sizeof(cmd_t));
    my_zappy_t *zappy = malloc(sizeof(my_zappy_t));
    client_info_t *info = init_clients_info(1, 10, 10);
    zappy->map = init_map(10, 10);

    zappy->client_list = (client_list_t *)init_list();
    list_add_client(zappy->client_list, info);

    zappy->client_list->first->info->player->direction = NORTH;

    zappy->client_list->first->info->player->x = 9;
    zappy->client_list->first->info->player->y = 9;

    cmd->args = malloc(sizeof(char *) * 2);
    cmd->args[0] = strdup("Forward");
    cmd->args[1] = NULL;

    forward(zappy, 1, cmd);
    right(zappy, 1, cmd);
    forward(zappy, 1, cmd);
    right(zappy, 1, cmd);
    forward(zappy, 1, cmd);
    right(zappy, 1, cmd);
    forward(zappy, 1, cmd);
    destroy_client_in_list(zappy->client_list, 1);
    free(zappy->client_list);
    free(zappy->map);
    free(zappy);
    free(cmd->args);
    free(cmd);
}