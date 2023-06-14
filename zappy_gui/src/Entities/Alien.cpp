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
    m_position.y = (m_tilePosition.x + m_tilePosition.y) * (TILE_WIDTH_HALF - TILE_ESCALATION) + WINDOW_HEIGHT / 4 -
            ALIEN_HEIGHT / 4;

    if (!m_baseTexture.loadFromFile(ALIEN_PATH)) {
        spdlog::error("Cannot load texture");
        throw std::runtime_error("Cannot load texture");
    }
    m_textures[Direction::NONE].loadFromImage(m_baseTexture.copyToImage(), sf::IntRect(0, 0, 84, 84));
    m_textures[Direction::NORTH].loadFromImage(m_baseTexture.copyToImage(), sf::IntRect(0, 0, 84, 84));
    m_textures[Direction::WEST].loadFromImage(m_baseTexture.copyToImage(), sf::IntRect(84, 0, 84, 84));
    m_textures[Direction::SOUTH].loadFromImage(m_baseTexture.copyToImage(), sf::IntRect(168, 0, 84, 84));
    m_textures[Direction::EAST].loadFromImage(m_baseTexture.copyToImage(), sf::IntRect(252, 0, 84, 84));
    m_sprite.setTexture(m_textures[Direction::WEST]);
    m_sprite.setPosition(m_position.x, m_position.y);
    m_sprite.setColor(zp::TeamManager::getTeamColor(teamName));
    m_sprite.setRotation(180);
    m_sprite.setScale(0.5, 0.5);
    m_sprite.setOrigin(42, 34);
    m_sprite.setPosition(m_position.x, m_position.y);
}

void zp::Alien::draw(sf::RenderTexture &window)
{
    auto color = zp::TeamManager::getTeamColor(m_teamName);
    if (color != m_sprite.getColor())
        m_sprite.setColor(color);
    window.draw(m_sprite);
}

void zp::Alien::setTilePosition(int x, int y)
{
    m_tilePosition.x = x;
    m_tilePosition.y = y;
    m_position.x = (m_tilePosition.x - m_tilePosition.y) * TILE_WIDTH_HALF + WINDOW_WIDTH / 2 + 48;
    m_position.y = (m_tilePosition.x + m_tilePosition.y) * (TILE_WIDTH_HALF - TILE_ESCALATION) + WINDOW_HEIGHT / 4 -
            ALIEN_HEIGHT / 4;
    m_sprite.setPosition(m_position.x, m_position.y);
}

void zp::Alien::setDirection(zp::Direction dir)
{
    m_direction = dir;
    m_sprite.setTexture(m_textures[dir]);
}
#include <iostream>

bool zp::Alien::onClick(sf::RenderWindow &window, sf::RenderTexture &renderTexture, sf::View &view, sf::Vector2f
mousePos)
{
    (void)view;
    (void)window;
    (void)renderTexture;
    (void)mousePos;
//    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
//    sf::Vector2f viewPosition = window.mapPixelToCoords(mousePosition, renderTexture.getView());
//    sf::Vector2i textureCoords = renderTexture.mapCoordsToPixel(viewPosition);
//    sf::Vector2f pos = {static_cast<float>(textureCoords.x), static_cast<float>(textureCoords.y)};
//    sf::Vector2i merde = {static_cast<int>(m_sprite.getPosition().x), static_cast<int>(m_sprite.getPosition().y)};
//    sf::Vector2f spritePos = window.mapPixelToCoords(merde, renderTexture.getView());
//    sf::Vector2f size = {static_cast<float>(m_textures[m_direction].getSize().x),
//                         static_cast<float>(m_textures[m_direction].getSize().y)};
//    sf::FloatRect rect = {spritePos, size};
//
//    std::cout << "MOUSE POS: " << mousePos.x << " " << mousePos.y << std::endl;
//    std::cout << "SPRITE POS: " << spritePos.x << " " << spritePos.y << std::endl;
//    if (rect.contains(mousePos)) {
//        std::cout << "CLICKED" << std::endl;
//        return true;
//    }
//    return false;
    return m_sprite.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)));
}
