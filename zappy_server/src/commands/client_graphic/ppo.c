/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** ppo
*/

#include "zappy_server.h"
#include "commands.h"

//ppo n X Y O\n                 ppo #n\n              player’s position
int ppo(my_zappy_t *zappy, int fd, char **args)
{
    char *result = NULL;

    if (zappy == NULL || args == NULL)
        return 0;
    if (count_args(args) != 2 || args[1][0] != '#') {
        send_message(fd, "Bad arguments\n");
        return 0;
    }
    return 0;
}
