/*
** EPITECH PROJECT, 2023
** src/Entities
** File description:
** Rock
*/

#include "Rock.hpp"

void zp::Rock::draw(sf::RenderTexture &window)
{
    window.draw(m_sprite);
}

void zp::Rock::setData(sf::Vector2i mapSize, sf::Vector2i tilePos, int rockId, sf::Texture &rockTexture)
{
    m_mapSize = mapSize;
    m_tilePosition = tilePos;
    m_position.x = (m_tilePosition.x - m_tilePosition.y + 1) * TILE_WIDTH_HALF + WINDOW_WIDTH / 2 + 48;
    m_position.y = (m_tilePosition.x + m_tilePosition.y + 1) * (TILE_HEIGHT_HALF - TILE_ESCALATION) + WINDOW_HEIGHT /
            (mapSize.y / 10);
    m_sprite.setTexture(rockTexture);
    m_sprite.setColor(zp::RockManager::randomColor(rockId));
    m_sprite.setScale(0.5, 0.5);
    m_sprite.setRotation(180);
    m_sprite.setPosition(m_position.x, m_position.y);
}
