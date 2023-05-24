/*
** EPITECH PROJECT, 2023
** zappy_gui
** File description:
** App
*/

#include "App.hpp"

zp::App::App()
{
    spdlog::info("Initializing application");
    try {
        m_windowManager = std::make_unique<WindowManager>("Zappy", sf::Vector2u(1920, 1080));
    } catch (const WindowManagerException &e) {
        throw e;
    }
}

void zp::App::run()
{
    while (m_windowManager->isOpen()) {
        m_windowManager->update();
    }
}
