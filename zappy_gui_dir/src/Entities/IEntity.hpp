/*
** EPITECH PROJECT, 2023
** src/Entities
** File description:
** IEntity
*/

#pragma once

#include <string>
#include <array>
#include <exception>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <spdlog/spdlog.h>

#include "Utils/RocksType.hpp"

#define FONT_PATH "assets/fonts/Roboto-Medium.ttf"

namespace zp
{

enum Direction
{
    NONE = 0,
    NORTH = 1,
    EAST = 2,
    SOUTH = 3,
    WEST = 4
};

class IEntity
{
public:
    virtual ~IEntity() = default;

    /**
     * @brief Draw the sprite
     */
    virtual void draw(sf::RenderTexture &window) = 0;

    /**
     * @brief Set the position of the entity on the map
     * @param x between 0 and 30
     * @param y between 0 and 30
     */
    virtual void setTilePosition(int x, int y, int mapHeight) = 0;

    /**
     * @brief Set the position of the entity on the window
     * @param dir NORTH EAST SOUTH WEST NONE
     */
    virtual void setDirection(Direction dir) = 0;

    /**
     * @brief returns the id of the player
     * @return id of the player
     */
    virtual int getId() const = 0;

    /**
     * @brief returns the team name of the player
     * @return team name of the player
     */
    virtual const std::string &getTeamName() const = 0;

    /**
     * @brief Set quantity of a rock in the inventory of the player
     * @param rock Rock to set quantity
     * @param quantity quantity value
     */
    virtual void setRockQuantity(Rocks rock, int quantity) = 0;

    /**
     * @brief Get inventory
     * @return Inventory const ref
     */
    virtual const std::unordered_map<Rocks, int> &getInventory() const = 0;

    /**
     * @brief Set incanting
     * @param incanting true if incanting
     */
    virtual void setIncanting(bool incanting) = 0;

    /**
     * @brief Get the position of the entity on the map
     * @return position of the entity on the map
     */
    virtual const sf::Vector2i getTilePosition() const = 0;

    /**
     * @brief Set the level of the entity
     * @param level level of the entity
     */
    virtual void setLevel(int level) = 0;

    /**
     * @brief Get the level of the entity
     * @return level of the entity
     */
    virtual int getLevel() const = 0;

protected:
    int m_id = -1;
    std::string m_teamName;
    sf::Texture m_baseTexture;
    std::array<sf::Texture, 5> m_textures;
    sf::Sprite m_sprite;
    sf::Vector2i m_position;
    sf::Vector2i m_tilePosition;
    sf::Font m_font;
    sf::Text m_text;
    Direction m_direction = Direction::WEST;
    int m_level = 1;

    std::unordered_map<Rocks, int> m_inventory;

};

} // zp
