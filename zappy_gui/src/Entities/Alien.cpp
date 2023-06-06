/*
** EPITECH PROJECT, 2023
** src/Entities
** File description:
** Alien
*/

#include "Alien.hpp"

zp::Alien::Alien(sf::Vector2i tilePos, zp::Direction dir, const std::string &teamName, int id)
{
    m_id = id;
    m_tilePosition = tilePos;
    m_direction = dir;
    m_teamName = teamName;
    m_position.x = m_tilePosition.x * 32 * 2 + 32;
    m_position.y = m_tilePosition.y * 32 * 2 + 32;

    if (!m_baseTexture.loadFromFile(ALIEN_PATH)) {
        spdlog::error("Cannot load texture");
        throw std::runtime_error("Cannot load texture");
    }
    m_textures[Direction::NORTH].loadFromImage(m_baseTexture.copyToImage(), sf::IntRect(0, 0, 84, 84));
    m_textures[Direction::WEST].loadFromImage(m_baseTexture.copyToImage(), sf::IntRect(84, 0, 84, 84));
    m_textures[Direction::SOUTH].loadFromImage(m_baseTexture.copyToImage(), sf::IntRect(168, 0, 84, 84));
    m_textures[Direction::EAST].loadFromImage(m_baseTexture.copyToImage(), sf::IntRect(252, 0, 84, 84));
    m_sprite.setTexture(m_textures[Direction::WEST]);
    m_sprite.setPosition(m_position.x, m_position.y);
}

void zp::Alien::draw(sf::RenderTexture &window)
{
    window.draw(m_sprite);
}

void zp::Alien::setTilePosition(int x, int y)
{
    m_tilePosition.x = x;
    m_tilePosition.y = y;
    m_position.x = m_tilePosition.x * 32 * 2 + 32;
    m_position.y = m_tilePosition.y * 32 * 2 + 32;
}

void zp::Alien::setDirection(zp::Direction dir)
{
    m_direction = dir;
    m_sprite.setTexture(m_textures[dir]);
}
