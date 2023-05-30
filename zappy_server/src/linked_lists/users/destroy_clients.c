/*
** EPITECH PROJECT, 2023
** B-NWP-400-REN-4-1-myteams-axel.rohee
** File description:
** destroy_user
*/

#include "clients.h"

static int destroy_user_info(client_t *user)
{
    if (!user || !user->info)
        return 0;
    if (user->info->username)
        free(user->info->username);
    if (user->info->fd)
        close(user->info->fd);
    free(user->info);
    return 0;
}

static int destroy_user(client_list_t *list, client_t *user)
{
    if (!user)
        return 0;
    destroy_user_info(user);
    if (list->first == user)
        list->first = user->next;
    if (list->last == user)
        list->last = user->prev;
    if (user->next)
        user->next->prev = user->prev;
    if (user->prev)
        user->prev->next = user->next;
    free(user);
    return 0;
}

int destroy_user_in_list(client_list_t *list, int fd)
{
    client_t *tmp = NULL;

    if (!list)
        return 0;
    tmp = list->first;
    for (tmp = list->first; tmp; tmp = tmp->next) {
        if (tmp->info->fd == fd) {
            destroy_user(list, tmp);
            return 0;
        }
    }
    return 0;
}
