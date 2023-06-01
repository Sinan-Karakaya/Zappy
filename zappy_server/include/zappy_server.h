/*
** EPITECH PROJECT, 2023
** B-YEP-400
** File description:
** zappy_server.h
*/

#ifndef teams_H_
    #define teams_H_

    #define _GNU_SOURCE

    #include "socket.h"
    #include "utils.h"
    #include "team.h"
    #include "map.h"
    #include "parsing.h"

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>
    #include <arpa/inet.h>
    #include <stdbool.h>
    #include <uuid/uuid.h>
    #include <stdlib.h>
    #include <string.h>

    #define MAX_NAME_LENGTH 32
    #define MAX_DESCRIPTION_LENGTH 255
    #define MAX_BODY_LENGTH 512

    typedef struct my_zappy_s {
        socket_t *server;
        team_list_t *team_list;
        client_list_t *client_list;
        map_t *map;
    } my_zappy_t;

    typedef struct fd_setters_s {
        fd_set ready_sockets;
        fd_set current_sockets;
        int max_fd;
    } fd_setters_t;

    typedef struct list_s {
        void *first;
        void *last;
    } list_t;

    my_zappy_t *init_zappy(parsing_t *parsing);
    list_t *init_list(void);

    // Sockets
    socket_t *create_socket(int port);
    socket_t *create_client_socket(int port);
    socket_t *connect_socket(char *client_ip, int port);
    void destroy_data(socket_t *data_socket);
    int close_socket(socket_t *my_socket);

    // Server
    int create_server(parsing_t *parsing);
    bool is_running(int sig);
    void sigint_handler(int sig);
    int handle_commands(my_zappy_t *zappy, int client_fd, char **args);
    int send_message(int fd, char *message);
    int send_message_lb(int fd, char *message);
    int send_message_error(int fd, char *message);
    int set_fds(socket_t *server, client_list_t *client_list);
    int calculate_fd_max(my_zappy_t *zappy);
    char **get_command(char *buffer);

    // Connections
    int accept_client(socket_t *server, client_list_t *client_list);

#endif /* !teams_H_ */
