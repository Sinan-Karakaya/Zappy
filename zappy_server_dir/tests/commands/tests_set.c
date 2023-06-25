/*
** EPITECH PROJECT, 2023
** zappy_server
** File description:
** tests_set
*/

#include <criterion/criterion.h>
#include "utils.h"
#include "commands.h"

Test (Set, Set_false)
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

    cmd->args = malloc(sizeof(char *) * 3);
    cmd->args[0] = strdup("Set");
    cmd->args[1] = strdup("Chocofraise");
    cmd->args[2] = NULL;

    set(zappy, 1, cmd);
    destroy_client_in_list(zappy->client_list, 1);
    free(zappy->client_list);
    free(zappy->map);
    free(zappy);
    for (int i = 0; cmd->args[i]; i++)
        free(cmd->args[i]);
    free(cmd->args);
    free(cmd);
}

Test (Set, Set_true)
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

    cmd->args = malloc(sizeof(char *) * 3);
    cmd->args[0] = strdup("Set");
    cmd->args[1] = strdup("food");
    cmd->args[2] = NULL;

    set(zappy, 1, cmd);
    destroy_client_in_list(zappy->client_list, 1);
    free(zappy->client_list);
    free(zappy->map);
    free(zappy);
    for (int i = 0; cmd->args[i]; i++)
        free(cmd->args[i]);
    free(cmd->args);
    free(cmd);
}

Test (Set, Set_false_bis)
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

    cmd->args = malloc(sizeof(char *) * 3);
    cmd->args[0] = strdup("Set");
    cmd->args[1] = strdup("deraumere");
    cmd->args[2] = NULL;

    set(zappy, 1, cmd);
    destroy_client_in_list(zappy->client_list, 1);
    free(zappy->client_list);
    free(zappy->map);
    free(zappy);
    for (int i = 0; cmd->args[i]; i++)
        free(cmd->args[i]);
    free(cmd->args);
    free(cmd);
}
