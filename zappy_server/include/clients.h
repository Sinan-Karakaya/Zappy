/*
** EPITECH PROJECT, 2023
** B-NWP-400-REN-4-1-myteams-axel.rohee
** File description:
** user
*/

#ifndef CLIENTS_H_
    #define CLIENTS_H_

    #include "my_id.h"
    #include <stdbool.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>

    #define LENGHT_INVENTORY 7

enum ressources {
    FOOD,
    LINEMATE,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME
};

enum orientation {
    NONE,
    NORTH,
    EAST,
    SOUTH,
    WEST
};

enum level {
    LVL1,
    LVL2,
    LVL3,
    LVL4,
    LVL5,
    LVL6,
    LVL7,
    LVL8
};

typedef struct {
    int x;
    int y;
    size_t inventory[LENGHT_INVENTORY];
    enum orientation direction;
    size_t lvl;
    double action_time;
    size_t id;
    size_t tick;
    bool is_incanting;
    bool is_alive;
} player_t;

typedef struct client_info_s {
    int fd;
    int user_id;
    int team_id;
    player_t *player;
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

/// @brief add a id to the list
/// @param list the list of id
/// @param id the id to add
void list_add_id(id_list_t *list, int id);

//  Initializers

/// @brief init a client info
/// @param fd the fd of the client
/// @return the client info
client_info_t *init_clients_info(int fd, int width, int height);

//  Getters

/// @brief get a client info by his id
/// @param list the list of clients
/// @param id the id of the client
/// @return the client info
client_info_t *get_client_info_by_id(client_list_t *list, int id);

/// @brief get a client info by his id player
/// @param list
/// @param id
/// @return the client info
client_info_t *get_client_info_by_id(client_list_t *list, int id);

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

/// @brief remove a id in the list
/// @param list the list of id
/// @param id the id to remove
int remove_id_in_list(id_list_t *list, int id);

#endif /* !CLIENTS_H_ */
