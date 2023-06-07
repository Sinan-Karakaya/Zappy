/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** init_time
*/

#include "my_time.h"
#include <stdlib.h>

static size_t get_time_per_tick(size_t frequency)
{
    return 1000000 / frequency;
}

void refresh_time_per_tick(my_time_t *init_time)
{
    init_time->time_per_tick = get_time_per_tick(init_time->time_per_tick);
}

my_time_t *init_time(size_t frequency)
{
    my_time_t *time = malloc(sizeof(my_time_t));

    if (!time)
        return NULL;
    time->actual = clock();
    time->last = clock();
    time->elapsed = 0;
    time->time_per_tick = get_time_per_tick(frequency);
    time->nb_ticks = 0;
    return time;
}
