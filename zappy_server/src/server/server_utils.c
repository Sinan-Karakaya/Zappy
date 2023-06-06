/*
** EPITECH PROJECT, 2023
** B-NWP-400-REN-4-1-myteams-thomas.juin
** File description:
** server_utils
*/

#include "zappy_server.h"
#include <signal.h>

bool is_running(int sig)
{
    static bool running = true;

    if (sig == SIGINT)
        running = false;
    return running;
}

void sigint_handler(int sig)
{
    if (sig == SIGINT)
        is_running(sig);
}

int set_fds(socket_t *server, client_list_t *client_list)
{
    FD_ZERO(&server->rset);
    FD_ZERO(&server->wset);
    FD_SET(server->sockfd, &server->rset);
    for (client_t *tmp = client_list->first; tmp != NULL; tmp = tmp->next) {
        FD_SET(tmp->info->fd, &server->rset);
        FD_SET(tmp->info->fd, &server->wset);
    }
    return 0;
}

int calculate_fd_max(my_zappy_t *zappy)
{
    int fd_max = 0;

    if (zappy->client_list->first == NULL)
        return zappy->server->sockfd;
    for (client_t *user = zappy->client_list->first;
        user != NULL; user = user->next) {
        if (user->info->fd > fd_max)
            fd_max = user->info->fd;
    }
    if (zappy->server->sockfd > fd_max)
        fd_max = zappy->server->sockfd;
    return fd_max;
}

char **free_command(char **command)
{
    if (!command)
        return NULL;
    for (size_t i = 0; command[i]; i++)
        free(command[i]);
    free(command);
    return NULL;
}
