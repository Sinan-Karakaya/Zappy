/*
** EPITECH PROJECT, 2023
** src/Entities
** File description:
** Alien
*/

#include "Alien.hpp"

zp::Alien::Alien(sf::Vector2i pos, sf::Vector2i tilePos, zp::Direction dir, const std::string &teamName)
{
    m_position = pos;
    m_tilePosition = tilePos;
    m_direction = dir;
    m_teamName = teamName;
    // @TODO: Load textures depending on directions
}

void zp::Alien::draw(sf::RenderTexture &window)
{
    (void)window;
    // @TODO: Draw sprite
}

void zp::Alien::setTilePosition(int x, int y)
{
    m_tilePosition.x = x;
    m_tilePosition.y = y;
    // @TODO: set sprite pos etc
}

void zp::Alien::setDirection(zp::Direction dir)
{
    m_direction = dir;
    // @TODO: Change sprite using texture array
}
