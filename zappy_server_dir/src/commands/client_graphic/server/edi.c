/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** edi
*/

#include "zappy_server.h"
#include "commands.h"

int edi(my_zappy_t *zappy, int id_egg)
{
    char *result = NULL;

    if (zappy == NULL)
        return 84;
    asprintf(&result, "edi %d\n", id_egg);
    send_to_graphics(zappy, result);
    free(result);
    return 0;
}
