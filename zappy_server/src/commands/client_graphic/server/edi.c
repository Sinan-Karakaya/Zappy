/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** edi
*/

#include "zappy_server.h"
#include "commands.h"

int edi(my_zappy_t *zappy, int fd, int id_egg)
{
    char *result = NULL;

    if (zappy == NULL)
        return 84;
    asprintf(&result, "edi %d\n", id_egg);
    send_message(fd, result);
    free(result);
    return 0;
}
