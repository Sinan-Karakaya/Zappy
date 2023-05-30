/*
** EPITECH PROJECT, 2023
** B-NWP-400-REN-4-1-myftp-thomas.juin
** File description:
** messages
*/

#include <string.h>
#include <unistd.h>

int send_message(int fd, char *message)
{
    if (write(fd, message, strlen(message)) == -1)
        return (84);
    return (0);
}

int send_message_lb(int fd, char *message)
{
    if (write(fd, message, strlen(message)) == -1)
        return (84);
    if (write(fd, "\n", 1) == -1)
        return (84);
    return (0);
}

int send_message_error(int fd, char *message)
{
    if (write(fd, message, strlen(message)) == -1)
        return (84);
    return (1);
}
