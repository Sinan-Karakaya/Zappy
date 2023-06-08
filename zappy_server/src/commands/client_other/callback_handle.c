/*
** EPITECH PROJECT, 2023
** zappy_server
** File description:
** callback_handle
*/

#include "zappy_server.h"
#include "commands.h"
#include "callback.h"

commands_time_t cmds_time[] = {
    /*
        PROTOCOL AI
    */
    {"Forward", &forward, 7},
    {"Right", &right, 7},
    {"Left", &left, 7},
    {"Look", &look, 7},
    {"Inventory", &inventory, 1},
    {"Broadcast", &broadcast, 7},
    {"Fork", &fork_cmd, 42},
    {"Eject", &eject, 7},
    {"Take", &take, 7},
    {"Set", &set, 7},
    {"Incantation", &incantation, 7},
    {NULL, NULL, 0}
};

int add_to_callback(my_zappy_t *zappy, int fd, cmd_t *cmd)
{
    callback_info_t *info = NULL;

    if (!zappy || !zappy->callback_list || !cmd)
        return 84;
    for (int i = 0; cmds_time[i].command != NULL; i++) {
        if (strcmp(cmd->args[0], cmds_time[i].command) == 0) {
            info = init_callback_info(fd, cmd, cmds_time[i].func,
            (time_vector_t){zappy->time->nb_ticks, cmds_time[i].time});
            list_add_callback((callback_list_t *)zappy->callback_list, info);
            return 0;
        }
    }
    printf("%s: Command (%s) not found\n", SERVER_RED, cmd->args[0]);
    return 84;
}

int handle_callbacks(my_zappy_t *zappy)
{
    callback_t *tmp = NULL;

    if (!zappy || !zappy->callback_list)
        return 84;
    for (callback_t *actual = zappy->callback_list->first; actual != NULL;
    actual = tmp)
        if (actual->info->tick_end <= zappy->time->nb_ticks) {
        tmp = actual->next;
        actual->info->func(zappy, actual->info->fd, actual->info->cmd);
        printf("%s: Callback %s executed for client %d \n", SERVER_YELLOW,
        actual->info->cmd->args[0], actual->info->fd);
        destroy_callback((callback_list_t *)zappy->callback_list, actual);
        } else
            tmp = actual->next;
    return 0;
}
