/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** pgt
*/

#include "zappy_server.h"
#include "commands.h"

int pgt(my_zappy_t *zappy, int fd, enum ressources ressource)
{
    char *result = NULL;

    if (zappy == NULL)
        return 0;
    asprintf(&result, "pgt %d %d\n", fd, ressource);
    send_message(fd, result);
    free(result);
    return 0;
}
