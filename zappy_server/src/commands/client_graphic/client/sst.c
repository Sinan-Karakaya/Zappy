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

    if (zappy == NULL || args == NULL)
        return 84;
    if (count_args(args) != 2)
        return send_message(fd, "ko\n");
    zappy->frequency = atoi(args[1]);
    asprintf(&result, "sgt %d\n", zappy->frequency);
    return 0;
}
