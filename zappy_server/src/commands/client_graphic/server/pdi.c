/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** pdi
*/

#include "zappy_server.h"
#include "commands.h"

int pdi(my_zappy_t *zappy, int fd)
{
    char *result = NULL;

    if (zappy == NULL)
        return 84;
    asprintf(&result, "pdi %d\n", fd);
    send_message(fd, result);
    free(result);
    return 0;
}
