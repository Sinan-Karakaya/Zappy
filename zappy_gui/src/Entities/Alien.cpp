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
    m_position.x = (m_tilePosition.x - m_tilePosition.y) * TILE_WIDTH_HALF + WINDOW_WIDTH / 2 + 48;
    m_position.y = (m_tilePosition.x + m_tilePosition.y) * (TILE_WIDTH_HALF - TILE_ESCALATION) + WINDOW_HEIGHT / 3 -
            ALIEN_HEIGHT / 4;

    if (!m_baseTexture.loadFromFile(ALIEN_PATH)) {
        spdlog::error("Cannot load texture");
        throw std::runtime_error("Cannot load texture");
    }
    m_baseTexture.setSmooth(true);
    m_textures[Direction::NONE].loadFromImage(m_baseTexture.copyToImage(), sf::IntRect(0, 0, 84, 84));
    m_textures[Direction::EAST].loadFromImage(m_baseTexture.copyToImage(), sf::IntRect(0, 0, 84, 84));
    m_textures[Direction::SOUTH].loadFromImage(m_baseTexture.copyToImage(), sf::IntRect(84, 0, 84, 84));
    m_textures[Direction::WEST].loadFromImage(m_baseTexture.copyToImage(), sf::IntRect(168, 0, 84, 84));
    m_textures[Direction::NORTH].loadFromImage(m_baseTexture.copyToImage(), sf::IntRect(252, 0, 84, 84));
    m_sprite.setTexture(m_textures[Direction::WEST]);
    m_sprite.setPosition(m_position.x, m_position.y);
    m_sprite.setColor(zp::TeamManager::getTeamColor(teamName));
    m_sprite.setRotation(180);
    m_sprite.setScale(0.5, 0.5);
    m_sprite.setOrigin(42, 34);
    m_sprite.setPosition(m_position.x, m_position.y);

    if (!m_font.loadFromFile(FONT_PATH)) {
        spdlog::error("Could not load font");
        throw std::runtime_error("Could not load font");
    }
    m_text.setFont(m_font);
    m_text.setCharacterSize(20);
    m_text.setFillColor(sf::Color::White);
    m_text.setOutlineColor(sf::Color::Black);
    m_text.setOutlineThickness(1);
    m_text.setRotation(180);
    m_text.setScale(-1, 1);
    m_text.setPosition(m_position.x - 10, m_position.y + 40);
    m_text.setString(std::to_string(m_id));
}

void zp::Alien::draw(sf::RenderTexture &window)
{
    auto color = zp::TeamManager::getTeamColor(m_teamName);
    if (color != m_sprite.getColor())
        m_sprite.setColor(color);
    window.draw(m_sprite);
    window.draw(m_text);
}

void zp::Alien::setTilePosition(int x, int y, int mapHeight)
{
    m_tilePosition.x = x;
    m_tilePosition.y = y;
    m_position.x = (m_tilePosition.x - m_tilePosition.y) * TILE_WIDTH_HALF + WINDOW_WIDTH / 2 + 48;
    m_position.y = (m_tilePosition.x + m_tilePosition.y) * (TILE_WIDTH_HALF - TILE_ESCALATION) + mapHeight -
            ALIEN_HEIGHT / 4;
    m_sprite.setPosition(m_position.x, m_position.y);
    m_text.setPosition(m_position.x - 10, m_position.y + 40);
}

void zp::Alien::setDirection(zp::Direction dir)
{
    m_direction = dir;
    m_sprite.setTexture(m_textures[dir]);
}
