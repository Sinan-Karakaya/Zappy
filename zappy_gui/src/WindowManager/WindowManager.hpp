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

#define BACKGROUND_PATH "assets/sprites/background.png"
#define FONT_PATH "assets/fonts/Roboto-Medium.ttf"
#define FONT_SIZE 16.0f

namespace zp {

class WindowManager
{
public:
    WindowManager(const std::string &title, const sf::Vector2u &size);
    ~WindowManager();

    /**
     * @brief Update the window
     * @param map Map to update
     */
    void update(std::unique_ptr<Map> &map);

    /**
     * @brief Check if the window is open
     * @return bool
     */
    bool isOpen();

private:
    /**
     * @brief Set the style of the window
     */
    void setStyle();

    /**
     * @brief Draw the ImGui windows
     */
    void drawImGui();

    /**
     * @brief Handle the events
     */
    void handleEvents();

    /**
     * @brief Render the window
     */
    void render();

    /**
     * @brief Draw the chat window
     */
    void drawChat();

    /**
     * @brief Draw the game window
     */
    void drawGame();

    /**
     * @brief Draw the control panel
     */
    void drawControlPanel();

private:
    sf::RenderWindow m_window;
    sf::Clock m_deltaClock;

    sf::RenderTexture m_gameTexture;
    sf::Sprite m_gameSprite;
    sf::Texture m_backgroundTexture;
    sf::Sprite m_backgroundSprite;
    sf::View m_gameView;
};

} // namespace zp
