/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** pic
*/

#include "zappy_server.h"
#include "commands.h"

int pic(my_zappy_t *zappy, client_t *client, id_list_t *list)
{
    char *result = NULL;
    char *tmp = "";

    if (!client || !list)
        return 0;
    for (my_id_t *my_id = list->first; my_id; my_id = my_id->next) {
        asprintf(&tmp, "%s%d ", tmp, my_id->id);
    }
    asprintf(&tmp, "%s%d", tmp, list->first->id);
    asprintf(&result, "pic %d %d %ld %s\n", client->info->player->x,
        client->info->player->y, client->info->player->lvl, tmp);
    send_to_graphics(zappy, result);
    free(result);
    free(tmp);
    return 0;
}
