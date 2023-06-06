/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** pbc
*/

#include "zappy_server.h"
#include "commands.h"

int pbc(my_zappy_t *zappy, int fd, char *message)
{
    char *result = NULL;
    client_t *client = NULL;

    if (zappy == NULL)
        return 0;
    asprintf(&result, "pbc %d %s\n", fd, message);
    return 0;
}
