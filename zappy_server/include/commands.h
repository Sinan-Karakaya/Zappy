/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** commands
*/

#ifndef COMMANDS_H_
    #define COMMANDS_H_

    #include "zappy_server.h"

    typedef struct commands_s {
        char *command;
        int (*func)(my_zappy_t *zappy, int fd, char **args);
    } commands_t;

/// @brief test function call when client is connected
/// @param zappy
/// @param fd
/// @param args
/// @return
int test(my_zappy_t *zappy, int fd, char **args);

/// @brief give the map size
/// @param zappy
/// @param fd
/// @param args
/// @return
int msz(my_zappy_t *zappy, int fd, char **args);

/// @brief give the content of a tile
/// @param zappy
/// @param fd
/// @param args
/// @return
int bct(my_zappy_t *zappy, int fd, char **args);

/// @brief give the content of the map (all the tiles)
/// @param zappy
/// @param fd
/// @param args
/// @return
int mct(my_zappy_t *zappy, int fd, char **args);

/// @brief name of all the teams in the server
/// @param zappy
/// @param fd
/// @param args
/// @return
int tna(my_zappy_t *zappy, int fd, char **args);

/// @brief give the player’s position
/// @param zappy
/// @param fd
/// @param args
/// @return
int ppo(my_zappy_t *zappy, int fd, char **args);

/// @brief give the player’s level
/// @param zappy
/// @param fd
/// @param args
/// @return
int plv(my_zappy_t *zappy, int fd, char **args);

/// @brief give the player’s inventory
/// @param zappy
/// @param fd
/// @param args
/// @return
int pin(my_zappy_t *zappy, int fd, char **args);

/// @brief give the time unit request
/// @param zappy
/// @param fd
/// @param args
/// @return
int sgt(my_zappy_t *zappy, int fd, char **args);

/// @brief give the time unit modification
/// @param zappy
/// @param fd
/// @param args
/// @return
int sst(my_zappy_t *zappy, int fd, char **args);

#endif /* !COMMANDS_H_ */