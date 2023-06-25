/*
** EPITECH PROJECT, 2023
** zappy_server
** File description:
** tests_incantation
*/

#include <criterion/criterion.h>
#include "utils.h"
#include "commands.h"

Test (Incantation, Incantation)
{
    cmd_t *cmd = malloc(sizeof(cmd_t));
    my_zappy_t *zappy = malloc(sizeof(my_zappy_t));
    client_info_t *info = init_clients_info(1, 10, 10);
    zappy->map = init_map(10, 10);
    zappy->callback_list = init_list();
    zappy->time = init_time(2);

    zappy->client_list = (client_list_t *)init_list();
    list_add_client(zappy->client_list, info);

    zappy->client_list->first->info->player->direction = NORTH;

    zappy->client_list->first->info->player->x = 9;
    zappy->client_list->first->info->player->y = 9;

    cmd->args = malloc(sizeof(char *) * 2);
    cmd->args[0] = strdup("Incantation");
    cmd->args[1] = NULL;

    zappy->map->tiles[9][9].inventory[LINEMATE] = 0;
    incantation(zappy, 1, cmd);
    zappy->map->tiles[9][9].inventory[LINEMATE] = 1;
    incantation(zappy, 1, cmd);
    destroy_client_in_list(zappy->client_list, 1);
    for (int i = 0; i < 3; i++)
        free(cmd->args[i]);
    free(cmd->args);
    destroy_callback((callback_list_t *)zappy->callback_list,
    zappy->callback_list->first);
    destroy_callback((callback_list_t *)zappy->callback_list,
    zappy->callback_list->first);
    free(zappy->callback_list);
    free(zappy->client_list);
    free(zappy->map);
    free(zappy->time);
    free(zappy);
}