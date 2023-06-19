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
#include "Entities/Rock.hpp"
#include "Tile.hpp"
#include "Utils/TeamManager.hpp"

#define TILE_PATH "assets/sprites/floor_zappy.png"
#define TILE_WIDTH_HALF 32
#define TILE_HEIGHT_HALF 32
#define TILE_ESCALATION 12

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
    const std::shared_ptr<Tile> &getTile(int x, int y) const;

    /**
     * @brief Add an alien to the map
     * @param alien
     */
    void addAlien(std::shared_ptr<zp::IEntity> alien);

    /**
     * @brief Add an egg to the map
     * @param egg
     */
    void addEgg(std::shared_ptr<zp::IEntity> egg);

    /**
     * @brief Add a team to the map
     * @param team
     */
    void addTeam(const std::string &team);

    /**
     * @brief Returns all aliens on the map
     * @return
     */
    const std::vector<std::shared_ptr<zp::IEntity>> &getAliens() const;

    /**
     * @brief Returns all eggs on the map
     * @return
     */
    const std::vector<std::shared_ptr<zp::IEntity>> &getEggs() const;

    /**
     * @brief Remove an alien from the map
     * @param id id of the alien
     */
    void removeAlien(int id);

    /**
     * @brief Remove an egg from the map
     * @param id id of the egg
     */
    void removeEgg(int id);

    /**
     * @brief Returns the size of the map
     * @return
     */
    const sf::Vector2i &getSize() const;

    /**
     * @brief Returns the teams
     * @return
     */
    const std::vector<std::string> &getTeams() const;

    /**
     * @brief Returns the time unit modifier
     * @return
     */
    int getTimeUnitModifier() const { return m_timeUnitModifier; }

    /**
     * @brief Set the time unit modifier
     * @param timeUnitModifier
     */
    void setTimeUnitModifier(int timeUnitModifier) { m_timeUnitModifier = timeUnitModifier;}

    /**
     * @brief Clear all data
     */
     void clearAll();

private:
    sf::Vector2i m_size = {0, 0};
    sf::Texture m_tileTexture;
    sf::Sprite m_tileSprite;
    std::array<sf::Texture, 7> m_rockTextures;

    std::vector<std::shared_ptr<Tile>> m_tiles;
    std::vector<std::shared_ptr<zp::IEntity>> m_aliens;
    std::vector<std::shared_ptr<zp::IEntity>> m_eggs;
    std::vector<std::string> m_teams;

    int m_timeUnitModifier = 1;
};

} // zp
