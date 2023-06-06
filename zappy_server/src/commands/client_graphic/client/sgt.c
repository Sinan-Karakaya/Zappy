/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** sgt
*/

#include "zappy_server.h"
#include "commands.h"

int sgt(my_zappy_t *zappy, int fd, char **args)
{
    char *result = NULL;

    if (zappy == NULL || args == NULL)
        return 84;
    if (count_args(args) != 1)
        return 84;
    asprintf(&result, "sgt %ld\n", zappy->frequency);
    send_message(fd, result);
    return 0;
}
