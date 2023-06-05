/*
** EPITECH PROJECT, 2023
** B-NWP-400-REN-4-1-myteams-axel.rohee
** File description:
** user
*/

#ifndef CLIENTS_H_
    #define CLIENTS_H_

    #include "my_uuid.h"
    #include <stdbool.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>

typedef struct client_info_s {
    int fd;
    bool is_logged;
    uuid_t user_uuid;
    char *username;
    uuid_t team_uuid;
} client_info_t;

typedef struct client_s client_t;
struct client_s {
    client_info_t *info;
    client_t *next;
    client_t *prev;
};

typedef struct client_list_s {
    client_t *first;
    client_t *last;
} client_list_t;


//  Adders

/// @brief add a client to the list
/// @param list the list of clients
/// @param info the info of the client
void list_add_client(client_list_t *list, client_info_t *info);

/// @brief add a uuid to the list
/// @param list the list of uuid
/// @param uuid the uuid to add
void list_add_uuid(uuid_list_t *list, uuid_t uuid);

//  Initializers

/// @brief init a client info
/// @param fd the fd of the client
/// @return the client info
client_info_t *init_clients_info(int fd);

//  Getters

/// @brief get a client info by his uuid
/// @param list the list of clients
/// @param uuid the uuid of the client
/// @return the client info
client_info_t *get_client_info_by_uuid(client_list_t *list, char *uuid);

/// @brief get a client by his uuid
/// @param list the list of clients
/// @param uuid the uuid of the client
/// @return the client
client_t *get_client_by_uuid(client_list_t *list, char *uuid);

/// @brief get a client by his fd
/// @param list the list of clients
/// @param fd the fd of the client
/// @return the client
client_t *get_client_by_fd(client_list_t *list, int fd);

// Deletors

/// @brief destroy a client info
/// @param user the client to destroy
/// @return 0
int destroy_client_in_list(client_list_t *list, int fd);

/// @brief remove a uuid in the list
/// @param list the list of uuid
/// @param uuid the uuid to remove
int remove_uuid_in_list(uuid_list_t *list, uuid_t uuid);

#endif /* !CLIENTS_H_ */
