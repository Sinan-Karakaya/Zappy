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
void list_add_client(client_list_t *list, client_info_t *info);
void list_add_uuid(uuid_list_t *list, uuid_t uuid);

//  Initializers
client_info_t *init_clients_info(int fd);

//  Getters
client_info_t *get_user_info_by_uuid(client_list_t *list, char *uuid);
client_t *get_user_by_uuid(client_list_t *list, char *uuid);
client_t *get_user_by_fd(client_list_t *list, int fd);

// Deletors
int destroy_user_in_list(client_list_t *list, int fd);
int remove_uuid_in_list(uuid_list_t *list, uuid_t uuid);

#endif /* !CLIENTS_H_ */
