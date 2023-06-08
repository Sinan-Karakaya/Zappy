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
#include <spdlog/spdlog.h>

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
    virtual void setTilePosition(int x, int y) = 0;

    /**
     * @brief Set the position of the entity on the window
     * @param dir NORTH EAST SOUTH WEST NONE
     */
    virtual void setDirection(Direction dir) = 0;

    /**
     * @brief
     * @return
     */
    virtual int getId() const = 0;

protected:
    int m_id = -1;
    std::string m_teamName;
    sf::Texture m_baseTexture;
    std::array<sf::Texture, 5> m_textures;
    sf::Sprite m_sprite;
    sf::Vector2i m_position;
    sf::Vector2i m_tilePosition;
    Direction m_direction = Direction::WEST;
};

} // zp
