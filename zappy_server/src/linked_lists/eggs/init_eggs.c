/*
** EPITECH PROJECT, 2023
** zappy_server
** File description:
** init_eggs
*/

#include "egg.h"
#include <stdlib.h>

egg_info_t *init_eggs_info(size_t team_id, size_t player_id, size_t x, size_t y)
{
    egg_info_t *info = calloc(1, sizeof(egg_info_t));

    if (info == NULL)
        return NULL;
    info->team_id = team_id;
    info->player_id = player_id;
    info->x = x;
    info->y = y;
    info->id = 0;
    return info;
}
