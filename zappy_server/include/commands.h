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

    int test(my_zappy_t *zappy, int fd, char **args);


#endif /* !COMMANDS_H_ */
