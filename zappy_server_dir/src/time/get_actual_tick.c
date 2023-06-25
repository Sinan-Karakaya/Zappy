/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** get_actual_tick
*/

#include "zappy_server.h"

static void tick_all_client(my_zappy_t *zappy)
{
    for (client_t *tmp = zappy->client_list->first; tmp; tmp = tmp->next) {
        if (tmp->info->team_id <= TEAM_ID_GRAPHIC)
            continue;
        tmp->info->player->actual_tick += 1;
    }
}

static void refill_ressources(my_zappy_t *zappy)
{
    if ((zappy->time->actual != zappy->time->last)
        && ((int)zappy->time->actual % 20 == 0)) {
            refill_map(zappy->map);
            send_to_graphics(zappy, "smg météorite\n");
        }
}

void get_actual_time(my_zappy_t *zappy, my_time_t *time)
{
    if (!time)
        return;
    time->actual = clock();
    time->elapsed = (time->actual - time->last);

    if (time->elapsed >= time->time_per_tick) {
        time->last = time->actual;
        time->nb_ticks += 1;
        refill_ressources(zappy);
        tick_all_client(zappy);
    }
}
