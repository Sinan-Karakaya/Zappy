/*
** EPITECH PROJECT, 2023
** B-NWP-400-REN-4-1-myteams-thomas.juin
** File description:
** socket
*/

#include "socket.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/// @brief print the error and return NULL
/// @param my_socket the socket in case of error
/// @param error the error to print
/// @return NULL
static socket_t *my_error(__attribute__((unused)) socket_t *my_socket,
char *error)
{
    if (!error)
        return (NULL);
    perror(error);
    return (NULL);
}

/// @brief init the adress of the socket
/// @param my_socket the socket to init
/// @param port the port to bind the socket to
/// @return 0 if success, 84 if error
static int init_adress(socket_t *my_socket, int port)
{
    my_socket->address.sin_family = AF_INET;
    my_socket->address.sin_addr.s_addr = INADDR_ANY;
    my_socket->address.sin_port = htons(port);
    my_socket->port = port;
    return (0);
}

socket_t *create_socket(int port)
{
    socket_t *my_socket = calloc(1, sizeof(socket_t));

    if (!my_socket)
        return my_error(my_socket, "malloc failed");
    my_socket->sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (my_socket->sockfd == 0)
        return my_error(my_socket, "socket failed");
    init_adress(my_socket, port);
    if (bind(my_socket->sockfd, (struct sockaddr *)&my_socket->address,
        sizeof(my_socket->address)) < 0) {
        return my_error(my_socket, "bind failed");
    }
    if (listen(my_socket->sockfd, 10) < 0)
        return my_error(my_socket, "listen failed");
    my_socket->addrlen = sizeof(my_socket->address);
    printf("%s: Started on port %d\n", SERVER_GREEN, port);
    return my_socket;
}

int destroy_socket(socket_t *my_socket)
{
    if (my_socket == NULL)
        return (84);
    close(my_socket->sockfd);
    free(my_socket);
    return (0);
}
