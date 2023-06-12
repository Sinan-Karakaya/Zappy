/*
** EPITECH PROJECT, 2023
** zappy_gui
** File description:
** App
*/

#include "App.hpp"

zp::App::App(const std::string &port, const std::string &ip)
{
    spdlog::info("Initializing application");
    try {
        m_chat = std::make_unique<Chat>();
        spdlog::info("Chat created");
        spdlog::info("Creating network manager");
        m_networkManager = std::make_unique<NetworkManager>(*m_chat);
        spdlog::info("Connecting to {}:{}", ip, port);
        m_networkManager->connect(port, ip);
        spdlog::info("Connected to {}:{}", ip, port);
        m_windowManager = std::make_unique<WindowManager>("Zappy", sf::Vector2u(1920, 1080));
        spdlog::info("Window created");
        m_map = std::make_unique<Map>();
        spdlog::info("Map created");
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
        m_windowManager->update(m_map, m_chat);
    }
}
