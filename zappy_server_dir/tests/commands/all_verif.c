/*
** EPITECH PROJECT, 2023
** zappy_server
** File description:
** all_verif
*/

#include <criterion/criterion.h>
#include "utils.h"
#include "commands.h"

Test (verif, Right)
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
    cmd->args[0] = strdup("Right");
    cmd->args[1] = NULL;

    verify_right(zappy, 1, cmd);
    destroy_client_in_list(zappy->client_list, 1);
    for (int i = 0; i < 2; i++)
        free(cmd->args[i]);
    free(cmd->args);
    destroy_callback((callback_list_t *)zappy->callback_list,
    zappy->callback_list->first);
    free(zappy->callback_list);
    free(zappy->client_list);
    free(zappy->map);
    free(zappy->time);
    free(zappy);
}

Test (verif, Left)
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
    cmd->args[0] = strdup("Left");
    cmd->args[1] = NULL;

    verify_left(zappy, 1, cmd);
    destroy_client_in_list(zappy->client_list, 1);
    for (int i = 0; i < 2; i++)
        free(cmd->args[i]);
    free(cmd->args);
    destroy_callback((callback_list_t *)zappy->callback_list,
    zappy->callback_list->first);
    free(zappy->callback_list);
    free(zappy->client_list);
    free(zappy->map);
    free(zappy->time);
    free(zappy);
}

Test (verif, fork)
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
    cmd->args[0] = strdup("Fork");
    cmd->args[1] = NULL;

    verify_fork(zappy, 1, cmd);
    destroy_client_in_list(zappy->client_list, 1);
    for (int i = 0; i < 2; i++)
        free(cmd->args[i]);
    free(cmd->args);
    destroy_callback((callback_list_t *)zappy->callback_list,
    zappy->callback_list->first);
    free(zappy->callback_list);
    free(zappy->client_list);
    free(zappy->map);
    free(zappy->time);
    free(zappy);
}

Test (verif, Forward)
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
    cmd->args[0] = strdup("Forward");
    cmd->args[1] = NULL;

    verify_forward(zappy, 1, cmd);
    destroy_client_in_list(zappy->client_list, 1);
    for (int i = 0; i < 2; i++)
        free(cmd->args[i]);
    free(cmd->args);
    destroy_callback((callback_list_t *)zappy->callback_list,
    zappy->callback_list->first);
    free(zappy->callback_list);
    free(zappy->client_list);
    free(zappy->map);
    free(zappy->time);
    free(zappy);
}

Test (verif, inventory)
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
    cmd->args[0] = strdup("Inventory");
    cmd->args[1] = NULL;

    verify_inventory(zappy, 1, cmd);
    destroy_client_in_list(zappy->client_list, 1);
    for (int i = 0; i < 2; i++)
        free(cmd->args[i]);
    free(cmd->args);
    destroy_callback((callback_list_t *)zappy->callback_list,
    zappy->callback_list->first);
    free(zappy->callback_list);
    free(zappy->client_list);
    free(zappy->map);
    free(zappy->time);
    free(zappy);
}

Test (verif, Look)
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
    cmd->args[0] = strdup("Look");
    cmd->args[1] = NULL;

    verify_look(zappy, 1, cmd);
    destroy_client_in_list(zappy->client_list, 1);
    for (int i = 0; i < 2; i++)
        free(cmd->args[i]);
    free(cmd->args);
    destroy_callback((callback_list_t *)zappy->callback_list,
    zappy->callback_list->first);
    free(zappy->callback_list);
    free(zappy->client_list);
    free(zappy->map);
    free(zappy->time);
    free(zappy);
}

Test (verif, Take)
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

    cmd->args = malloc(sizeof(char *) * 3);
    cmd->args[0] = strdup("Take");
    cmd->args[1] = strdup("food");
    cmd->args[2] = NULL;

    verify_take(zappy, 1, cmd);
    destroy_client_in_list(zappy->client_list, 1);
    for (int i = 0; i < 3; i++)
        free(cmd->args[i]);
    free(cmd->args);
    destroy_callback((callback_list_t *)zappy->callback_list,
    zappy->callback_list->first);
    free(zappy->callback_list);
    free(zappy->client_list);
    free(zappy->map);
    free(zappy->time);
    free(zappy);
}

Test (verif, Set)
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

    cmd->args = malloc(sizeof(char *) * 3);
    cmd->args[0] = strdup("Set");
    cmd->args[1] = strdup("food");
    cmd->args[2] = NULL;

    verify_set(zappy, 1, cmd);
    destroy_client_in_list(zappy->client_list, 1);
    for (int i = 0; i < 3; i++)
        free(cmd->args[i]);
    free(cmd->args);
    destroy_callback((callback_list_t *)zappy->callback_list, zappy->callback_list->first);
    free(zappy->callback_list);
    free(zappy->client_list);
    free(zappy->map);
    free(zappy->time);
    free(zappy);
}

Test (verif, Incantation)
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

    cmd->args = malloc(sizeof(char *) * 2);
    cmd->args[0] = strdup("Incantation");
    cmd->args[1] = NULL;

    forward(zappy, 1, cmd);
    zappy->map->tiles[info->player->y][info->player->x].inventory[LINEMATE] = 0;
    verify_incantation(zappy, 1, cmd);
    zappy->map->tiles[info->player->y][info->player->x].inventory[LINEMATE] = 1;
    verify_incantation(zappy, 1, cmd);
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