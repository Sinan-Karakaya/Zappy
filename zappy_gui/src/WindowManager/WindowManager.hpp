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
#include "Utils/GameManager.hpp"

#define BACKGROUND_PATH "assets/sprites/background.png"
#define FONT_PATH "assets/fonts/Roboto-Medium.ttf"
#define FONT_SIZE 16.0f

#define MAX_ZOOM 1.0f
#define MIN_ZOOM 0.5f

namespace zp {

inline static const std::array<std::string, NUM_OF_ROCKS> g_rocksToString = {
    "Food",
    "Linemate",
    "Deraumere",
    "Sibur",
    "Mendiane",
    "Phiras",
    "Thystame"
};

inline static const std::array<std::string, 8> g_elevationGuide = {
    "elevation players linemate deraumere sibur mendiane phiras thystame",
    "1->2 1 1 0 0 0 0 0",
    "2->3 2 1 1 1 0 0 0",
    "3->4 2 2 0 1 0 2 0",
    "4->5 4 1 1 2 0 1 0",
    "5->6 4 1 2 1 3 0 0",
    "6->7 6 1 2 3 0 1 0",
    "7->8 6 2 2 2 2 2 1"
};

class WindowManager
{
public:
    WindowManager(const std::string &title, const sf::Vector2u &size, const std::string &ip, const std::string &port,
                  bool &isConnected);
    ~WindowManager();

    /**
     * @brief Update the window
     * @param map Map to update
     * @param chat Chat to update
     */
    void update(std::unique_ptr<Map> &map, std::unique_ptr<Chat> &chat);

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
    void drawImGui(const Map &map, const Chat &chat);

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
    void drawChat(const Chat &chat, Map &map);

    /**
     * @brief Draw the game window
     */
    void drawGame();

    /**
     * @brief Draw the control panel
     */
    void drawDetails(const Map &map);

    /**
     * @brief Draw the control panel
     * @param map
     */
    void drawControlPanel(const Map &map);

    /**
     * @brief Draw the tiles details
     * @param map
     */
    void drawTilesDetails(const Map &map);

    /**
     * @brief Draw the players details
     * @param map
     */
    void drawGuide(const Map &map);

    /**
     * @brief Draw the connection window depending on the state of isConnected
     */
     void drawConnection();

     /**
      * @brief Draw the inventory window if m_inventoryToDraw is not -1
      */
      void drawInventory(Map &map);

private:
    sf::RenderWindow m_window;
    sf::Clock m_deltaClock;

    sf::RenderTexture m_gameTexture;
    sf::Sprite m_gameSprite;
    sf::Texture m_backgroundTexture;
    sf::Sprite m_backgroundSprite;
    sf::View m_gameView;
    float m_zoom = 1.0f;
    sf::Vector2f m_viewPos = {0.0f, 0.0f};

    std::string m_ip;
    std::string m_port;
    bool &m_isConnected;

    bool m_showInventory = false;
};

} // namespace zp
