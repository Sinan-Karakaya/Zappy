/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** enw
*/

#include "zappy_server.h"
#include "commands.h"

int enw(my_zappy_t *zappy, egg_t *egg)
{
    char *result = NULL;

    if (zappy == NULL)
        return 84;
    asprintf(&result, "enw %ld %ld %ld %ld\n", egg->info->id,
    egg->info->player_id, egg->info->x, egg->info->y);
    send_to_graphics(zappy, result);
    free(result);
    return 0;
}
