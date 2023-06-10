/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** pic
*/

#include "zappy_server.h"
#include "commands.h"

int pic(client_t *client, id_list_t *list)
{
    char *result = NULL;
    char *tmp = "";

    if (!client || !list)
        return 0;
    while (list->first->next) {
        asprintf(&tmp, "%s%d ", tmp, list->first->id);
        list = (id_list_t *)list->first->next;
    }
    asprintf(&tmp, "%s%d", tmp, list->first->id);
    asprintf(&result, "pic %d %d %ld %s\n", client->info->player->x,
        client->info->player->y, client->info->player->lvl, tmp);
    send_message(client->info->fd, result);
    free(result);
    free(tmp);
    return 0;
}
