/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** smg
*/

#include "zappy_server.h"
#include "commands.h"

int smg(my_zappy_t *zappy, int fd, char *message)
{
    char *result = NULL;

    if (zappy == NULL)
        return 84;
    asprintf(&result, "smg %s\n", message);
    send_message(fd, result);
    return 0;
}
