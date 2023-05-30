/*
** EPITECH PROJECT, 2023
** B-YEP-400-REN-4-1-zappy-thomas.juin
** File description:
** main
*/

#include "zappy_server.h"

int main(int ac, char **av)
{
    if (ac < 2)
        return (84);
    create_server(av);
    return (0);
}