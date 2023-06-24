/*
** EPITECH PROJECT, 2023
** zappy_server
** File description:
** tests_broadcast
*/

#include <criterion/criterion.h>
#include "utils.h"
#include "commands.h"

Test (Broadcast, Broadcast)
{
    cmd_t *cmd = malloc(sizeof(cmd_t));
    my_zappy_t *zappy = malloc(sizeof(my_zappy_t));
    client_info_t *info = init_clients_info(1, 10, 10);
    zappy->map = init_map(10, 10);
    client_info_t *info_bis = init_clients_info(1, 10, 10);

    zappy->client_list = (client_list_t *)init_list();
    list_add_client(zappy->client_list, info);
    list_add_client(zappy->client_list, info_bis);

    zappy->client_list->first->info->player->direction = NORTH;

    zappy->client_list->first->info->player->x = 9;
    zappy->client_list->first->info->player->y = 9;
    zappy->client_list->last->info->player->x = 10;
    zappy->client_list->last->info->player->y = 9;

    cmd->args = malloc(sizeof(char *) * 3);
    cmd->args[0] = strdup("Broadcast");
    cmd->args[1] = strdup("Hello");
    cmd->args[2] = NULL;

    broadcast(zappy, 1, cmd);
    destroy_client_in_list(zappy->client_list, 1);
    destroy_client_in_list(zappy->client_list, 1);
    free(cmd->args);
}