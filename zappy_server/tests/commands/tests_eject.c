/*
** EPITECH PROJECT, 2023
** zappy_server
** File description:
** tests_eject
*/


#include <criterion/criterion.h>
#include "utils.h"
#include "commands.h"

/*
Test (Eject, Eject)
{
    char *args[] = {"Eject", NULL};
    cmd_t *cmd = init_cmd(args);
    my_zappy_t *zappy = malloc(sizeof(my_zappy_t));
    client_info_t *info = init_clients_info(1, 10, 10);
    zappy->map = init_map(10, 10);
    client_info_t *info_bis = init_clients_info(2, 10, 10);
    zappy->egg_list = (egg_list_t *)init_list();

    zappy->client_list = (client_list_t *)init_list();
    list_add_client(zappy->client_list, info);
    list_add_client(zappy->client_list, info_bis);

    zappy->client_list->first->info->player->direction = NORTH;
    zappy->client_list->last->info->player->direction = NORTH;

    zappy->client_list->first->info->player->x = 9;
    zappy->client_list->first->info->player->y = 9;
    zappy->client_list->last->info->player->x = 9;
    zappy->client_list->last->info->player->y = 9;

    cmd->args = malloc(sizeof(char *) * 2);
    cmd->args[0] = strdup("Eject");
    cmd->args[1] = NULL;

    forward(zappy, 1, cmd);
    forward(zappy, 2, cmd);
    eject(zappy, 1, cmd);
    destroy_client_in_list(zappy->client_list, 1);
    destroy_client_in_list(zappy->client_list, 1);
    free(zappy->client_list);
    free(zappy->map);
    free(zappy);
    free(cmd->args);
    free(cmd);
}
*/
