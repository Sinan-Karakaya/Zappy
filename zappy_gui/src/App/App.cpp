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
        m_networkManager = std::make_unique<NetworkManager>();
        std::cout << "1" << std::endl;
        m_networkManager->connect();
        std::cout << "2" << std::endl;
        m_windowManager = std::make_unique<WindowManager>("Zappy", sf::Vector2u(1920, 1080));
        std::cout << "3" << std::endl;
        m_map = std::make_unique<Map>();
    } catch (const WindowManagerException &e) {
        throw e;
    } catch (const std::runtime_error &e) {
        throw e;
    } catch (const std::exception &e) {
        throw e;
    }
}

void zp::App::run()
{
    while (m_windowManager->isOpen()) {
        m_networkManager->update(m_map);
        m_windowManager->update();
    }
}
