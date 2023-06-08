/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** enw
*/

#include "zappy_server.h"
#include "commands.h"

int enw(my_zappy_t *zappy, int fd, int id_egg, vector_t pos_egg)
{
    char *result = NULL;

    if (zappy == NULL)
        return 84;
    asprintf(&result, "enw %d %d %d %d\n", id_egg, fd, pos_egg.x, pos_egg.y);
    return 0;
}
