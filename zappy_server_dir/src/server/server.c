/*
** EPITECH PROJECT, 2023
** B-NWP-400-REN-4-1-myteams-thomas.juin
** File description:
** server
*/

#include "zappy_server.h"
#include "commands.h"
#include "callback.h"
#include "free.h"
#include <ctype.h>
#include <signal.h>
#include <unistd.h>

static char *read_input(int fd)
{
    char buffer[1024] = {0};
    size_t size = 0;

    while (true) {
        if ((strlen(buffer) >= 2 && buffer[strlen(buffer) - 2] == '\r'
        && buffer[strlen(buffer) - 1] == '\n')
        || (strlen(buffer) >= 1 && buffer[strlen(buffer) - 1] == '\n'))
            break;
        size = read(fd, buffer + strlen(buffer), 1);
        if (size == 0)
            return NULL;
    }
    return strdup(buffer);
}

static int read_loop(my_zappy_t *zappy, int fd)
{
    char *buffer = NULL;
    cmd_t *cmd = NULL;
    client_t *client = get_client_by_fd(zappy->client_list, fd);
    char **tmp = NULL;
    if (FD_ISSET(fd, &zappy->server->rset)) {
        if (!(buffer = read_input(fd)))
            return disconnect_player(zappy, fd);
    } if (FD_ISSET(fd, &zappy->server->wset)) {
        if (buffer) {
            tmp = get_command(buffer), cmd = init_cmd(tmp);
            handle_commands(zappy, fd, cmd);
            send_all_message(cmd, fd);
        } if (!client || !zappy)
            return 84;
        if (exec_command(client, cmd, zappy, fd) != 0)
            send_message(fd, "ko\n");
    } if (buffer)
        free(buffer);
    destroy_cmd(cmd), free_array(tmp);
    return false;
}

static int read_cmd(my_zappy_t *zappy)
{
    client_t *actual = NULL;
    client_t *tmp = NULL;

    if (!zappy || !zappy->client_list)
        return 84;
    eat_all_client(zappy);
    actual = zappy->client_list->first;
    while (actual != NULL) {
        tmp = actual->next;
        read_loop(zappy, actual->info->fd);
        actual = tmp;
    }
    return 0;
}

static void time_manager(my_zappy_t *zappy)
{
    get_actual_time(zappy, zappy->time);
    handle_callbacks(zappy);
}

int create_server(parsing_t *parsing)
{
    my_zappy_t *zappy = init_zappy(parsing);
    int fd_max = 0;

    if (!zappy)
        return 84;
    signal(SIGINT, sigint_handler);
    srand(time(NULL));
    while (is_running(0)) {
        if (zappy->is_end)
            break;
        set_fds(zappy->server, zappy->client_list);
        fd_max = calculate_fd_max(zappy);
        if (select(fd_max + 1, &zappy->server->rset, &zappy->server->wset,
        NULL, NULL) == -1)
            break;
        if (accept_client(zappy) == 84)
            return 84;
        read_cmd(zappy), time_manager(zappy);
    } signal(SIGINT, SIG_DFL);
    return free_zappy(zappy);
}
