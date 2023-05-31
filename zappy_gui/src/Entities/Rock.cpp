/*
** EPITECH PROJECT, 2023
** src/Entities
** File description:
** Rock
*/

#include "Rock.hpp"

zp::Rock::Rock(sf::Vector2i pos, sf::Vector2i tilePos, zp::Direction dir, const std::string &teamName)
{
    m_position = pos;
    m_tilePosition = tilePos;
    m_direction = LEFT;
    m_teamName = "rock";
    // @TODO: Load textures depending on directions
}

void zp::Rock::draw(sf::RenderTexture &window)
{
    (void)window;
    // @TODO: Draw sprite
}

void zp::Rock::setTilePosition(int x, int y)
{
    m_tilePosition.x = x;
    m_tilePosition.y = y;
    // @TODO: set sprite pos etc
}

void zp::Rock::setDirection(zp::Direction dir)
{
    return;
    // @TODO: Change sprite using texture array
}