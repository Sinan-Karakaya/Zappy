/*
** EPITECH PROJECT, 2023
** project (Workspace) [WSL: Ubuntu-22.04]
** File description:
** main
*/

#include <unistd.h>

#include "App/App.hpp"

static void printHelp()
{
    std::cout << "USAGE: ./zappy_gui -p port -h machine" << std::endl;
    std::cout << "\tport\tis the port number" << std::endl;
    std::cout << "\tmachine\tis the name of the machine; localhost by default" << std::endl;
}

static int handleOpt(int ac, char **av, std::string &ip, std::string &port)
{
    int opt;

    while ((opt = getopt(ac, av, "p:h:")) != -1) {
        if (opt == 'p')
            port = std::string(optarg);
        else if (opt == 'h')
            ip = std::string(optarg);
        else {
            printHelp();
            return 1;
        }
    }
    for (; optind < ac; optind++) {
        if (std::string(av[optind]) == "-help") {
            printHelp();
            return 1;
        }
    }
    return 0;
}

int main(int ac, char **av)
{
    std::string ip;
    std::string port;

    if (handleOpt(ac, av, ip, port))
        return 0;
    if (port.empty()) {
        printHelp();
        return 1;
    }
    try {
        zp::App app(port, ip);
        app.run();
    } catch (const zp::WindowManagerException &e) {
        spdlog::error(e.what());
        return 84;
    } catch (const std::exception &e) {
        spdlog::error(e.what());
        return 84;
    }

    return 0;
}