/*
** EPITECH PROJECT, 2023
** src/Map
** File description:
** Map
*/

#pragma once

#include <vector>
#include <memory>

#include <spdlog/spdlog.h>
#include <SFML/Graphics.hpp>

#include "Entities/IEntity.hpp"
#include "Tile.hpp"
#include "Utils/TeamManager.hpp"

#define TILE_PATH "assets/sprites/floor_zappy.png"
#define TILE_WIDTH_HALF 32
#define TILE_HEIGHT_HALF 32
#define TILE_ESCALATION 8

namespace zp
{

class Map
{
public:
    Map(int x = 0, int y = 0);
    ~Map() = default;

    /**
     * @brief Draw the map on the window, the players, the rocks, and other entities
     * @param window
     */
    void drawMap(sf::RenderTexture &window);

    /**
     * @brief Set the size of the map
     * @param x
     * @param y
     */
    void setSize(int x = 0, int y = 0);

    /**
     * @brief Get the tile at (x, y)
     * @param x Must be between 0 and 30
     * @param y Must be between 0 and 30
     * @return std::shared_ptr<Tile>
     */
    std::shared_ptr<Tile> getTile(int x, int y);

    /**
     * @brief Add an alien to the map
     * @param alien
     */
    void addAlien(std::shared_ptr<zp::IEntity> alien);

    /**
     * @brief Add a rock to the map
     * @param rock
     */
    void addRock(std::shared_ptr<zp::IEntity> rock);

    /**
     * @brief Add a team to the map
     * @param team
     */
    void addTeam(const std::string &team);

    /**
     * @brief Returns all aliens on the map
     * @return
     */
    std::vector<std::shared_ptr<zp::IEntity>> &getAliens();

    /**
     * @brief Remove an alien from the map
     * @param id id of the alien
     */
    void removeAlien(int id);

    /**
     * @brief Returns all rocks on the map
     * @return
     */
    std::vector<std::shared_ptr<zp::IEntity>> &getRocks();

    /**
     * @brief Returns the teams
     * @return
     */
    const std::vector<std::string> & getTeams() const;

private:
    sf::Vector2i m_size = {0, 0};
    sf::Texture m_tileTexture;
    sf::Sprite m_tileSprite;

    std::vector<std::shared_ptr<Tile>> m_tiles;
    std::vector<std::shared_ptr<zp::IEntity>> m_rocks;
    std::vector<std::shared_ptr<zp::IEntity>> m_aliens;
    std::vector<std::string> m_teams;
};

} // zp
