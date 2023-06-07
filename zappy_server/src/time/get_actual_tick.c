/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** get_actual_tick
*/

#include "zappy_server.h"

void get_actual_time(my_time_t *time)
{
    if (!time)
        return;
    time->actual = clock();
    time->elapsed = (time->actual - time->last);

    if (time->elapsed >= time->time_per_tick) {
        time->last = time->actual;
        time->nb_ticks += 1;
    }
}
