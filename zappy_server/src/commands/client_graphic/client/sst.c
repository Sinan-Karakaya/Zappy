/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** sst
*/

#include "zappy_server.h"
#include "commands.h"

int sst(my_zappy_t *zappy, int fd, char **args)
{
    char *result = NULL;
    int value = 0;

    if (zappy == NULL || args == NULL)
        return 84;
    if (count_args(args) != 2)
        return send_message(fd, "ko\n");
    value = atoi(args[1]);
    if (value <= 1 || value > 10000)
        return send_message(fd, UNKNOWN_PARAMETER);
    zappy->frequency = value;
    refresh_time_per_tick(zappy);
    asprintf(&result, "sgt %ld\n", zappy->frequency);
    send_message(fd, result);
    free(result);
    return 0;
}
