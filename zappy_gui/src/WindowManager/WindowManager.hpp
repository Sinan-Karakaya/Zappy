/*
** EPITECH PROJECT, 2023
** project (Workspace) [WSL: Ubuntu-22.04]
** File description:
** WindowManager
*/

#pragma once

#include <string>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <spdlog/spdlog.h>

#include <imgui.h>
#include <imgui-SFML.h>

#include "WindowManagerException.hpp"
#include "NetworkManager/NetworkManager.hpp"
#include "Map/Map.hpp"

namespace zp {

class WindowManager
{
public:
    WindowManager(const std::string &title, const sf::Vector2u &size);
    ~WindowManager();

    void update();
    bool isOpen();

private:
    void setStyle();
    void drawImGui();
    void handleEvents();
    void render();

    void drawChat();
    void drawGame();
    void drawControlPanel();

private:
    sf::RenderWindow m_window;
    sf::RenderTexture m_renderTexture;
    sf::Clock m_deltaClock;

    sf::RenderTexture m_gameTexture;
    sf::Sprite m_gameSprite;

    NetworkManager m_networkManager;
    Map m_map;
};

} // namespace zp
