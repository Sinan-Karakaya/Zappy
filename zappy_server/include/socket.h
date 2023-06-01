/*
** EPITECH PROJECT, 2023
** B-NWP-400-REN-4-1-myteams-axel.rohee
** File description:
** socket
*/

#ifndef SOCKET_H_
    #define SOCKET_H_

    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <netinet/ip.h>
    #include <sys/select.h>
    #include <sys/types.h>
    #include <sys/socket.h>

    typedef struct socket_s {
        int sockfd;
        int port;
        struct sockaddr_in address;
        socklen_t addrlen;

        fd_set rset;
        fd_set wset;
    } socket_t;

    /// @brief create a socket and bind it to the port
    /// @param port the port to bind the socket to
    /// @return a socket_t struct with the socket fd and the port number
    socket_t *create_socket(int port);

    /// @brief destroy a socket
    /// @param my_socket the socket to destroy
    /// @return 0 if success, 84 if error
    int destroy_socket(socket_t *my_socket);

#endif /* !SOCKET_H_ */
