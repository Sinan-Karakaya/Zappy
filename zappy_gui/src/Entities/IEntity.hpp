/*
** EPITECH PROJECT, 2023
** src/Entities
** File description:
** IEntity
*/

#pragma once

#include <string>
#include <array>

#include <SFML/Graphics.hpp>

namespace zp
{

enum Direction
{
    NONE = 0,
    LEFT = 1,
    UP = 2,
    RIGHT = 3,
    DOWN = 4
};

class IEntity
{
public:
    virtual ~IEntity() = default;

    virtual void draw(sf::RenderTexture &window) = 0;
    virtual void setTilePosition(int x, int y) = 0;
    virtual void setDirection(Direction dir) = 0;
//    virtual void writeToChat(Chat &chat) = 0;

protected:
    std::string m_teamName;
    std::array<sf::Texture, 4> m_textures;
    sf::Sprite m_sprite;
    sf::Vector2i m_position;
    sf::Vector2i m_tilePosition;
    Direction m_direction;
};

} // zp
