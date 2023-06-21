/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** commands
*/

#ifndef COMMANDS_H_
    #define COMMANDS_H_

    #include "zappy_server.h"
    #include "callback.h"

    typedef struct commands_s {
        char *command;
        int (*func)(my_zappy_t *zappy, int fd, cmd_t *cmd);
    } commands_t;

    typedef struct commands_time_s {
        char *command;
        int (*func)(my_zappy_t *zappy, int fd, cmd_t *cmd);
        size_t time;
    } commands_time_t;

    typedef struct incantation_s {
        size_t level;
        size_t nb_players;
        size_t ressources[7];
    } incantation_t;

/// @brief set the team of the player
/// @param zappy
/// @param fd
/// @param cmd
/// @return 0 if ok, 84 if error
int set_team(my_zappy_t *zappy, int fd, cmd_t *cmd);

/// @brief add a command to the list
/// @param cmd
/// @param str
/// @return 0 if ok, 84 if error
int add_cmd(cmd_t *cmd, char *str);


/// @brief init the cmd struct
/// @param args the args
/// @return the cmd struct
cmd_t *init_cmd(char **args);


/// @brief send a message to all the players
/// @param cmd
/// @param fd
/// @return 0 if ok, 84 if error
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
int pic(my_zappy_t *zappy, client_t *client, id_list_t *list);

/// @brief function call when an incantation is finish
/// @param zappy
/// @param client
/// @param result
/// @return
int pie(my_zappy_t *zappy, client_t *client, char *result);

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
int enw(my_zappy_t *zappy, egg_t *egg);

/// @brief player connection for an egg
/// @param zappy
/// @param fd
/// @return
int ebo(my_zappy_t *zappy, int id_egg);

/// @brief death of an egg
/// @param zappy
/// @param fd
/// @return
int edi(my_zappy_t *zappy, int id_egg);

/// @brief end of an egg
/// @param zappy
/// @param team_name
/// @return
int seg(my_zappy_t *zappy, char *team_name);

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

/// @brief check if the client is alive
/// @param zappy
/// @param fd
/// @return 0 if the function succeed, 84 otherwise
int check_alive(my_zappy_t *zappy, int fd);

/// @brief incantation function
/// @param zappy
/// @param fd
/// @param cmd
/// @return 0 if the function succeed, 84 otherwise
int incantation(my_zappy_t *zappy, int fd, cmd_t *cmd);

/// @brief the callback function for the incantation
/// @param zappy
/// @param fd
/// @param cmd
/// @return 0 if the function succeed, 84 otherwise
int verify_incantation(my_zappy_t *zappy, int fd, cmd_t *cmd);

/// @brief check all values for the incantation
/// @param zappy
/// @param fd
/// @return 0 if the function succeed, 84 otherwise
int verify_all_values_incantation(my_zappy_t *zappy, int fd);

/// @brief freeze all the clients on the tile for the incantation
/// @param zappy
/// @param fd
/// @return 0 if the function succeed, 84 otherwise
int lock_client(my_zappy_t *zappy, int fd);

/// @brief remove the resources for the incantation
/// @param zappy
/// @param x
/// @param y
/// @param lvl
/// @return 0 if the function succeed, 84 otherwise
int remove_resources_incantation(my_zappy_t *zappy, size_t x, size_t y,
int lvl);

/// @brief unlock all the clients on the tile for the incantation
/// @param zappy
/// @param fd
/// @param succeed
/// @return 0 if the function succeed, 84 otherwise
int unlock_clients(my_zappy_t *zappy, int fd, bool succeed);

/// @brief move the player to where he is looking
/// @param zappy
/// @param fd
/// @param cmd
/// @return 0 if the function succeed, 84 otherwise
int forward(my_zappy_t *zappy, int fd, cmd_t *cmd);

/// @brief  the callback function for the forward
/// @param zappy
/// @param fd
/// @param cmd
/// @return 0 if the function succeed, 84 otherwise
int verify_forward(my_zappy_t *zappy, int fd, cmd_t *cmd);

/// @brief hatch an egg on the tile of the player
/// @param zappy
/// @param fd
/// @param cmd
/// @return 0 if the function succeed, 84 otherwise
int fork_cmd(my_zappy_t *zappy, int fd, cmd_t *cmd);

/// @brief the callback function for the fork
/// @param zappy
/// @param fd
/// @param cmd
/// @return 0 if the function succeed, 84 otherwise
int verify_fork(my_zappy_t *zappy, int fd, cmd_t *cmd);

/// @brief eject all the players of the tile
/// @param zappy
/// @param fd
/// @param cmd
/// @return 0 if the function succeed, 84 otherwise
int eject(my_zappy_t *zappy, int fd, cmd_t *cmd);

/// @brief the callback function for the eject
/// @param zappy
/// @param fd
/// @param cmd
/// @return 0 if the function succeed, 84 otherwise
int verify_eject(my_zappy_t *zappy, int fd, cmd_t *cmd);


/// @brief broadcast a message to all the clients
/// @param zappy
/// @param fd
/// @param cmd
/// @return 0 if the function succeed, 84 otherwise
int broadcast(my_zappy_t *zappy, int fd, cmd_t *cmd);

/// @brief the callback function for the broadcast
/// @param zappy
/// @param fd
/// @param cmd
/// @return 0 if the function succeed, 84 otherwise
int verify_broadcast(my_zappy_t *zappy, int fd, cmd_t *cmd);

/// @brief send the inventory of the player
/// @param zappy
/// @param fd
/// @param cmd
/// @return 0 if the function succeed, 84 otherwise
int inventory(my_zappy_t *zappy, int fd, cmd_t *cmd);

/// @brief the callback function for the inventory
/// @param zappy
/// @param fd
/// @param cmd
/// @return 0 if the function succeed, 84 otherwise
int verify_inventory(my_zappy_t *zappy, int fd, cmd_t *cmd);


/// @brief take an object on the tile of the player
/// @param zappy
/// @param fd
/// @param cmd
/// @return 0 if the function succeed, 84 otherwise
int take(my_zappy_t *zappy, int fd, cmd_t *cmd);

/// @brief the callback function for the take
/// @param zappy
/// @param fd
/// @param cmd
int verify_take(my_zappy_t *zappy, int fd, cmd_t *cmd);

/// @brief set an object on the tile of the player
/// @param zappy
/// @param fd
/// @param cmd
/// @return 0 if the function succeed, 84 otherwise
int set(my_zappy_t *zappy, int fd, cmd_t *cmd);

/// @brief the callback function for the set
/// @param zappy
/// @param fd
/// @param cmd
/// @return 0 if the function succeed, 84 otherwise
int verify_set(my_zappy_t *zappy, int fd, cmd_t *cmd);

/// @brief turn the player to the right
/// @param zappy
/// @param fd
/// @param cmd
/// @return 0 if the function succeed, 84 otherwise
int right(my_zappy_t *zappy, int fd, cmd_t *cmd);

/// @brief the callback function for the right
/// @param zappy
/// @param fd
/// @param cmd
/// @return 0 if the function succeed, 84 otherwise
int verify_right(my_zappy_t *zappy, int fd, cmd_t *cmd);

/// @brief look around the player and send the result to the client
/// @param zappy
/// @param fd
/// @param cmd
/// @return 0 if the function succeed, 84 otherwise
int look(my_zappy_t *zappy, int fd, cmd_t *cmd);

/// @brief the callback function for the look
/// @param zappy
/// @param fd
/// @param cmd
/// @return 0 if the function succeed, 84 otherwise
int verify_look(my_zappy_t *zappy, int fd, cmd_t *cmd);

/// @brief turn the player to the left
/// @param zappy
/// @param fd
/// @param cmd
/// @return 0 if the function succeed, 84 otherwise
int left(my_zappy_t *zappy, int fd, cmd_t *cmd);

/// @brief the callback function for the left
/// @param zappy
/// @param fd
/// @param cmd
/// @return 0 if the function succeed, 84 otherwise
int verify_left(my_zappy_t *zappy, int fd, cmd_t *cmd);

/// @brief send the numbers of players connected to the server
/// @param zappy
/// @param fd
/// @param cmd
/// @return 0 if the function succeed, 84 otherwise
int connect_nbr(my_zappy_t *zappy, int fd, cmd_t *cmd);

/// @brief callback function for the connect_nbr
/// @param zappy
/// @param fd
/// @param cmd
/// @return 0 if the function succeed, 84 otherwise
int verify_connect_nbr(my_zappy_t *zappy, int fd, cmd_t *cmd);

// Commands utils

/// @brief send the position of the player to the graphics
/// @param zappy
/// @param client
/// @return 0 if the function succeed, 84 otherwise
int send_pos_to_graphics(my_zappy_t *zappy, client_t *client);

/// @brief send the inventory of the player to the graphics
/// @param zappy
/// @param client
/// @return 0 if the function succeed, 84 otherwise
int send_inventory_to_graphics(my_zappy_t *zappy, client_t *client);

#endif /* !COMMANDS_H_ */
