/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** test
*/

#include "zappy_server.h"
#include "commands.h"

int test(my_zappy_t *zappy, int fd, char **args)
{
    if (zappy == NULL || args == NULL)
        return 0;
    send_message(fd, "Hello World!\n");
    return 0;
}
