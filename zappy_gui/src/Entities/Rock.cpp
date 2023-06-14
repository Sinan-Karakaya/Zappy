/*
** EPITECH PROJECT, 2023
** src/Entities
** File description:
** Rock
*/

#include "Rock.hpp"

zp::Rock::Rock(sf::Vector2i tilePos, zp::Direction dir, const std::string &teamName)
{
    (void)teamName;
    (void)dir;
    m_tilePosition = tilePos;
    m_position.x = m_tilePosition.x * 32 * 2 + 32;
    m_position.y = m_tilePosition.y * 32 * 2 + 32;
    m_direction = EAST;
    m_teamName = "rock";

    if (!m_baseTexture.loadFromFile(TILE_PATH)) {
        spdlog::error("Cannot load texture");
        throw std::runtime_error("Cannot load texture");
    }
    m_sprite.setTexture(m_baseTexture);
    m_sprite.setTextureRect(sf::IntRect(128, 0, 128, 128));
}

void zp::Rock::draw(sf::RenderTexture &window)
{
    window.draw(m_sprite);
}

void zp::Rock::setTilePosition(int x, int y)
{
    m_tilePosition.x = x;
    m_tilePosition.y = y;
    // @TODO: set sprite pos etc
}

void zp::Rock::setDirection(zp::Direction dir)
{
    m_direction = dir;
    // @TODO: Change sprite using texture array
}

bool zp::Rock::onClick(sf::RenderWindow &window, sf::RenderTexture &renderTexture, sf::View &view, sf::Vector2f
mousePos)
{
    (void)window;
    (void)view;
    (void)renderTexture;
    (void)mousePos;
    return false;
}
