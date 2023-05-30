/*
** EPITECH PROJECT, 2023
** B-NWP-400-REN-4-1-myteams-thomas.juin
** File description:
** connection
*/

#include "zappy_server.h"

int accept_client(socket_t *server, client_list_t *client_list)
{
    int fd_actual = 0;
    struct sockaddr_in address;
    socklen_t addrlen = sizeof(address);
    client_info_t *client_info = NULL;

    if (!server)
        return 84;
    if (FD_ISSET(server->sockfd, &server->rset)) {
        fd_actual = accept(server->sockfd,
        (struct sockaddr *)&address, &addrlen);
        if (fd_actual == -1) {
            return 84;
        }
        dprintf(1, "Connection from %s:%d\n", inet_ntoa(address.sin_addr),
        ntohs(server->address.sin_port));
        client_info = init_clients_info(fd_actual);
        list_add_client(client_list, client_info);
    }
    return fd_actual;
}
