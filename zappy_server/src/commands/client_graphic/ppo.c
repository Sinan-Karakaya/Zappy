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
    if (count_args(args) != 2)
        return send_message(fd, "ko\n");
    return 0;
}
