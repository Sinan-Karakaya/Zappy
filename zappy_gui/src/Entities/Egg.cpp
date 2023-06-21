/*
** EPITECH PROJECT, 2023
** zappy_gui
** File description:
** Egg
*/

#include "Egg.hpp"

zp::Egg::Egg(sf::Vector2i tilePos, zp::Direction dir, const std::string &teamName, int id)
{
    m_id = id;
    m_tilePosition = tilePos;
    m_direction = dir;
    m_teamName = teamName;
    m_position.x = (m_tilePosition.x - m_tilePosition.y) * TILE_WIDTH_HALF + WINDOW_WIDTH / 2 + 48;
    m_position.y = (m_tilePosition.x + m_tilePosition.y) * (TILE_WIDTH_HALF - TILE_ESCALATION) + WINDOW_HEIGHT / 3 -
                   EGG_HEIGHT / 8;

    if (!m_baseTexture.loadFromFile(EGG_PATH)) {
        spdlog::error("Cannot load texture");
        throw std::runtime_error("Cannot load texture");
    }
    m_baseTexture.setSmooth(true);
    m_sprite.setTexture(m_baseTexture);
    m_sprite.setPosition(m_position.x, m_position.y);
    m_sprite.setColor(zp::TeamManager::getTeamColor(teamName));
    m_sprite.setRotation(180);
    m_sprite.setScale(0.25, 0.25);
    m_sprite.setOrigin(EGG_WIDTH / 4, EGG_HEIGHT / 4);
    m_sprite.setPosition(m_position.x, m_position.y);
}

void zp::Egg::draw(sf::RenderTexture &window)
{
    auto color = zp::TeamManager::getTeamColor(m_teamName);
    if (color != m_sprite.getColor())
        m_sprite.setColor(color);
    window.draw(m_sprite);
}

void zp::Egg::setTilePosition(int x, int y, int mapHeight)
{
    m_tilePosition.x = x;
    m_tilePosition.y = y;
    m_position.x = (m_tilePosition.x - m_tilePosition.y) * TILE_WIDTH_HALF + WINDOW_WIDTH / 2 + 48;
    m_position.y = (m_tilePosition.x + m_tilePosition.y) * (TILE_WIDTH_HALF - TILE_ESCALATION) + mapHeight -
                   EGG_HEIGHT / 8;
    m_sprite.setPosition(m_position.x, m_position.y);
}

void zp::Egg::setDirection(zp::Direction dir)
{
    m_direction = dir;
}