/*
** EPITECH PROJECT, 2023
** B-YEP-400
** File description:
** zappy_server.h
*/

#ifndef Zappy_Server_H_
    #define Zappy_Server_H_

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
    #include <time.h>


    #define MAX_NAME_LENGTH 32
    #define MAX_DESCRIPTION_LENGTH 255
    #define MAX_BODY_LENGTH 512

    typedef struct my_zappy_s {
        socket_t *server;
        team_list_t *team_list;
        client_list_t *client_list;
        size_t frequency;
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

    /// @brief init the zappy server
    /// @param parsing the parsing struct
    /// @return the zappy struct
    my_zappy_t *init_zappy(parsing_t *parsing);

    /// @brief init the list
    /// @return the list
    list_t *init_list(void);

    // Server


    /// @brief create and run the server
    /// @param parsing the parsing struct
    /// @return 0 if success, 84 if error
    int create_server(parsing_t *parsing);

    /// @brief handle the commands from the client
    /// @param zappy the zappy struct
    /// @param client_fd the fd of the client
    /// @param args the args of the command
    /// @return 0 if success, 84 if error
    int handle_commands(my_zappy_t *zappy, int client_fd, char **args);

    /// @brief set the fd of the server and the clients
    /// @param server the socket of the server
    /// @param client_list the list of clients
    /// @return 0 if success, 84 if error
    int set_fds(socket_t *server, client_list_t *client_list);

    /// @brief calculate the max fd
    /// @param zappy the zappy struct
    /// @return the max fd
    int calculate_fd_max(my_zappy_t *zappy);


    /// @brief get the command from the buffer
    /// @param buffer the buffer
    /// @return the command
    char **get_command(char *buffer);

    /// @brief send a message to the client
    /// @param fd the fd of the client
    /// @param message the message to send
    /// @return 0 if success, 84 if error
    int send_message(int fd, char *message);

    /// @brief send a message to the client with a line break
    /// @param fd the fd of the client
    /// @param message the message to send
    /// @return 0 if success, 84 if error
    int send_message_lb(int fd, char *message);

    /// @brief send a message to the client with an error
    /// @param fd the fd of the client
    /// @param message the message to send
    /// @return 1 if success, 84 if error
    int send_message_error(int fd, char *message);

    bool is_running(int sig);
    void sigint_handler(int sig);

    // Connections
    int accept_client(socket_t *server, client_list_t *client_list);

#endif /* !Zappy_Server_H_ */
