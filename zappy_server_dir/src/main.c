/*
** EPITECH PROJECT, 2023
** B-YEP-400-REN-4-1-zappy-thomas.juin
** File description:
** main
*/

#include "zappy_server.h"

int print_usage(void)
{
    printf("USAGE: ./zappy_server -p port -x width -y height -n name1 name2 \
... -c clientsNb -f freq\n");
    printf("\tport\t\tis the port number\n");
    printf("\twidth\t\tis the width of the world\n");
    printf("\theight\t\tis the height of the world\n");
    printf("\tnameX\t\tis the name of the team X\n");
    printf("\tclientsNb\tis the number of authorized clients per team\n");
    printf("\tfreq\t\tis the reciprocal of time unit for execution of \
actions\n");
    return (84);
}

int main(int ac, char **av)
{
    parsing_t *parsing = NULL;

    if (((ac == 2 && strcmp(av[1], "-help") == 0)
    || (ac == 2 && (strcmp(av[1], "-h") == 0))))
        return (print_usage());
    parsing = do_parsing(av);
    if (!parsing)
        return (84);
    create_server(parsing);
    return (0);
}
