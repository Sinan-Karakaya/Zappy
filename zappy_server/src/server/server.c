/*
** EPITECH PROJECT, 2023
** B-NWP-400-REN-4-1-myteams-thomas.juin
** File description:
** server
*/

#include "zappy_server.h"
#include "free.h"
#include <ctype.h>
#include <signal.h>
#include <unistd.h>

static char *read_input(int fd)
{
    char buffer[1024] = {0};

    while (true) {
        if (strlen(buffer) >= 2 && buffer[strlen(buffer) - 2] == '\r'
        && buffer[strlen(buffer) - 1] == '\n')
            break;
        read(fd, buffer + strlen(buffer), 1);
    }
    return strdup(buffer);
}

static int read_loop(my_zappy_t *zappy, int fd)
{
    char *buffer = NULL;
    char **cmd = NULL;

    if (FD_ISSET(fd, &zappy->server->rset)) {
        if (!(buffer = read_input(fd))) {
            return 84;
        }
    } if (FD_ISSET(fd, &zappy->server->wset)) {
        if (buffer) {
            cmd = get_command(buffer);
            handle_commands(zappy, fd, cmd);
            cmd = free_command(cmd);
        }
    } if (buffer)
        free(buffer);
    return false;
}

static int read_cmd(my_zappy_t *zappy)
{
    client_t *tmp = NULL;

    if (!zappy || !zappy->client_list)
        return 84;
    tmp = zappy->client_list->first;
    while (tmp != NULL) {
        read_loop(zappy, tmp->info->fd);
        tmp = tmp->next;
    }
    return 0;
}

int create_server(parsing_t *parsing)
{
    my_zappy_t *zappy = init_zappy(parsing);
    int fd_max = 0;

    if (!zappy)
        return 84;
    signal(SIGINT, sigint_handler);
    while (is_running(0)) {
        set_fds(zappy->server, zappy->client_list);
        fd_max = calculate_fd_max(zappy);
        if (select(fd_max + 1, &zappy->server->rset, &zappy->server->wset,
        NULL, NULL) == -1)
            break;
        if (accept_client(zappy->server, zappy->client_list) == 84)
            return 84;
        read_cmd(zappy);
    }
    signal(SIGINT, SIG_DFL);
    return free_zappy(zappy);
}