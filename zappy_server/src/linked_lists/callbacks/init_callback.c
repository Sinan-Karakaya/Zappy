/*
** EPITECH PROJECT, 2023
** B-NWP-400-REN-4-1-myteams-axel.rohee
** File description:
** init_zappy
*/

#include "callback.h"
#include "zappy_server.h"
#include "utils.h"

static cmd_t *copy_cmd(cmd_t *cmd)
{
    cmd_t *new_cmd = calloc(1, sizeof(cmd_t));

    if (new_cmd == NULL)
        return NULL;
    new_cmd->args = dup_array(cmd->args);
    new_cmd->result = calloc(1, sizeof(char *));
    if (new_cmd->result == NULL)
        return NULL;
    return new_cmd;
}

callback_info_t *init_callback_info(int fd, cmd_t *cmd,
int (*func)(my_zappy_t *zappy, int fd, cmd_t *cmd), time_vector_t delay)
{
    callback_info_t *info = calloc(1, sizeof(callback_info_t));

    if (info == NULL)
        return NULL;
    info->cmd = copy_cmd(cmd);
    info->fd = fd;
    info->func = func;
    info->tick_start = delay.tick_start;
    info->tick_delay = delay.tick_delay;
    info->tick_end = info->tick_start + info->tick_delay;
    return info;
}
