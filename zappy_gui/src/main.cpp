/*
** EPITECH PROJECT, 2023
** project (Workspace) [WSL: Ubuntu-22.04]
** File description:
** main
*/

#include "App/App.hpp"

int main(int ac, char **av)
{
    (void)ac;
    (void)av;

    try {
        zp::App app;
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