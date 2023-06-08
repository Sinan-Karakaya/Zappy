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
        int (*func)(my_zappy_t *zappy, int fd, cmd_t *cmd);
    } commands_t;

int set_team(my_zappy_t *zappy, int fd, cmd_t *cmd);
int add_cmd(cmd_t *cmd, char *str);
cmd_t *init_cmd(char **args);
int send_all_message(cmd_t *cmd, int fd);

/*
PROTOCOLE GRAPHICS
*/

/// @brief give the map size
/// @param zappy
/// @param fd
/// @param args
/// @return
int msz(my_zappy_t *zappy, int fd, cmd_t *cmd);

/// @brief give the content of a tile
/// @param zappy
/// @param fd
/// @param args
/// @return
int bct(my_zappy_t *zappy, int fd, cmd_t *cmd);

/// @brief give the content of the map (all the tiles)
/// @param zappy
/// @param fd
/// @param args
/// @return
int mct(my_zappy_t *zappy, int fd, cmd_t *cmd);

/// @brief name of all the teams in the server
/// @param zappy
/// @param fd
/// @param args
/// @return
int tna(my_zappy_t *zappy, int fd, cmd_t *cmd);

/// @brief give the player’s position
/// @param zappy
/// @param fd
/// @param args
/// @return
int ppo(my_zappy_t *zappy, int fd, cmd_t *cmd);

/// @brief give the player’s level
/// @param zappy
/// @param fd
/// @param args
/// @return
int plv(my_zappy_t *zappy, int fd, cmd_t *cmd);

/// @brief give the player’s inventory
/// @param zappy
/// @param fd
/// @param args
/// @return
int pin(my_zappy_t *zappy, int fd, cmd_t *cmd);

/// @brief give the time unit request
/// @param zappy
/// @param fd
/// @param args
/// @return
int sgt(my_zappy_t *zappy, int fd, cmd_t *cmd);

/// @brief give the time unit modification
/// @param zappy
/// @param fd
/// @param args
/// @return
int sst(my_zappy_t *zappy, int fd, cmd_t *cmd);

/// @brief give some informations about the player
/// @param zappy
/// @param fd
/// @return
int pnw(my_zappy_t *zappy, int fd);

/// @brief function call when a player use expulsion
/// @param zappy
/// @param fd
/// @return
int pex(my_zappy_t *zappy, int fd);

/// @brief function call when a player use broadcast
/// @param zappy
/// @param fd
/// @param message
/// @return
int pbc(my_zappy_t *zappy, int fd, char *message);

/// @brief function call when a player start an incantation
/// @param zappy
/// @param fd
/// @return
int pic(my_zappy_t *zappy, int fd);

/// @brief function call when an incantation is finish
/// @param zappy
/// @param fd
/// @return
int pie(my_zappy_t *zappy, int fd);

/// @brief egg laying by the player
/// @param zappy
/// @param fd
/// @return
int pfk(my_zappy_t *zappy, int fd);

/// @brief when player drop ressources
/// @param zappy
/// @param fd
/// @param ressource
/// @return
int pdr(my_zappy_t *zappy, int fd, enum ressources ressource);

/// @brief when player take ressources
/// @param zappy
/// @param fd
/// @param
/// @return
int pgt(my_zappy_t *zappy, int fd, enum ressources ressource);

/// @brief when player die
/// @param zappy
/// @param fd
/// @return
int pdi(my_zappy_t *zappy, int fd);

/// @brief an egg was laid by a player
/// @param zappy
/// @param fd
/// @return
int enw(my_zappy_t *zappy, int fd, int id_egg, vector_t pos_egg);

/// @brief player connection for an egg
/// @param zappy
/// @param fd
/// @return
int ebo(my_zappy_t *zappy, int fd, int id_egg);

/// @brief death of an egg
/// @param zappy
/// @param fd
/// @return
int edi(my_zappy_t *zappy, int fd, int id_egg);

/// @brief end of an egg
/// @param zappy
/// @param fd
/// @return
int seg(my_zappy_t *zappy, int fd);

/// @brief send message from the server
/// @param zappy
/// @param fd
/// @param message
/// @return
int smg(my_zappy_t *zappy, int fd, char *message);

/// @brief unknown command
/// @param zappy
/// @param fd
/// @return
int suc(my_zappy_t *zappy, int fd);

/// @brief command parameter
/// @param zappy
/// @param fd
/// @return
int sbp(my_zappy_t *zappy, int fd);

/*
PROTOCOLE IA
*/

int check_alive(my_zappy_t *zappy, int fd);
int incantation(my_zappy_t *zappy, int fd, cmd_t *cmd);
int forward(my_zappy_t *zappy, int fd, cmd_t *cmd);
int fork_cmd(my_zappy_t *zappy, int fd, cmd_t *cmd);
int eject(my_zappy_t *zappy, int fd, cmd_t *cmd);
int broadcast(my_zappy_t *zappy, int fd, cmd_t *cmd);
int inventory(my_zappy_t *zappy, int fd, cmd_t *cmd);
int take(my_zappy_t *zappy, int fd, cmd_t *cmd);
int set(my_zappy_t *zappy, int fd, cmd_t *cmd);
int right(my_zappy_t *zappy, int fd, cmd_t *cmd);
int look(my_zappy_t *zappy, int fd, cmd_t *cmd);
int left(my_zappy_t *zappy, int fd, cmd_t *cmd);
int connect_nbr(my_zappy_t *zappy, int fd, cmd_t *cmd);

#endif /* !COMMANDS_H_ */
