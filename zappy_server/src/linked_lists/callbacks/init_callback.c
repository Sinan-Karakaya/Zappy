/*
** EPITECH PROJECT, 2023
** B-NWP-400-REN-4-1-myteams-axel.rohee
** File description:
** init_zappy
*/

#include "callback.h"
#include "zappy_server.h"
#include "utils.h"

callback_info_t *init_callback_info(int fd, cmd_t *cmd,
int (*func)(my_zappy_t *zappy, int fd, cmd_t *cmd), time_vector_t delay)
{
    callback_info_t *info = calloc(1, sizeof(callback_info_t));

    if (info == NULL)
        return NULL;
    info->cmd = cmd;
    info->fd = fd;
    info->func = func;
    info->tick_start = delay.tick_start;
    info->tick_delay = delay.tick_delay;
    info->tick_end = info->tick_start + info->tick_delay;
    return info;
}
