/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** pdr
*/

#include "zappy_server.h"
#include "commands.h"

int pdr(my_zappy_t *zappy, int fd, enum ressources ressource)
{
    char *result = NULL;

    if (zappy == NULL)
        return 0;
    asprintf(&result, "pdr %d %d\n", fd, ressource);
    return 0;
}
