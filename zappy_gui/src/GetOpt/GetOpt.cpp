/*
** EPITECH PROJECT, 2023
** src/GetOpt
** File description:
** GetOpt
*/

#include "GetOpt.hpp"

void zp::GetOpt::printHelp()
{
    std::cout << "USAGE: ./zappy_gui -p port -h machine" << std::endl;
    std::cout << "\tport\tis the port number" << std::endl;
    std::cout << "\tmachine\tis the name of the machine; localhost by default" << std::endl;
}

int zp::GetOpt::parseOpt(int ac, char **av, std::string &ip, std::string &port)
{
    int opt;

    while ((opt = getopt(ac, av, "p:h:")) != -1) {
        if (opt == 'p')
            port = std::string(optarg);
        else if (opt == 'h')
            ip = std::string(optarg);
    }
    for (int i = 0; av[i]; i++) {
        if (std::string(av[i]) == "-help") {
            printHelp();
            return 1;
        }
    }
    return 0;
}