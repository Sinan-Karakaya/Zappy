/*
** EPITECH PROJECT, 2023
** src/Map
** File description:
** Map
*/

#include "Map.hpp"
#include <iostream>

zp::Map::Map(int x, int y) : m_size(x, y)
{
    m_tiles.reserve(x * y);
    if (!m_tileTexture.loadFromFile(TILE_PATH)) {
        spdlog::error("Could not load texture");
        throw std::runtime_error("Could not load texture");
    }
    m_tileSprite.setTexture(m_tileTexture);
    m_tileSprite.setTextureRect(sf::IntRect(0, 0, 128, 128));
    m_tileSprite.setScale(0.5, 0.5);
    m_tileSprite.setRotation(180);
}

void zp::Map::drawMap(sf::RenderTexture &window)
{
    if (m_size.x == 0 || m_size.y == 0)
        return;

//    auto size = window.getSize();
    for (int i = m_size.x; i > 0; i--) {
        for (int j = m_size.y - 1; j >= 0; j--) {
            m_tileSprite.setPosition((i - j) * TILE_WIDTH_HALF + 1920 / 2 + 48, (i + j) * (TILE_HEIGHT_HALF -
            TILE_ESCALATION) + 1080 / (m_size.y / 10));
            window.draw(m_tileSprite);
        }
    }
    for (auto &rock : m_rocks) {
        rock->draw(window);
    }
    for (auto &alien : m_aliens) {
        alien->draw(window);
    }
}

void zp::Map::setSize(int x, int y)
{
    spdlog::info("Setting map size to: {} {}", x, y);
    m_size.x = x;
    m_size.y = y;
    m_tiles.clear();
    m_tiles.reserve(x * y);
    for (int i = 0; i < x * y; i++) {
        m_tiles.push_back(std::make_shared<zp::Tile>());
    }
}

const std::shared_ptr<zp::Tile> &zp::Map::getTile(int x, int y) const
{
    return m_tiles[y * m_size.y + x];
}

const sf::Vector2i &zp::Map::getSize() const
{
    return m_size;
}

void zp::Map::addAlien(std::shared_ptr<zp::IEntity> alien)
{
    m_aliens.push_back(alien);
}

void zp::Map::addRock(std::shared_ptr<zp::IEntity> rock)
{
    m_rocks.push_back(rock);
}

const std::vector<std::shared_ptr<zp::IEntity>> &zp::Map::getAliens() const
{
    return m_aliens;
}

const std::vector<std::shared_ptr<zp::IEntity>> &zp::Map::getRocks() const
{
    return m_rocks;
}

void zp::Map::removeAlien(int id)
{
    for (auto it = m_aliens.begin(); it != m_aliens.end(); it++) {
        if ((*it)->getId() == id) {
            m_aliens.erase(it);
            return;
        }
    }
}

const std::vector<std::string> &zp::Map::getTeams() const
{
    return m_teams;
}

void zp::Map::addTeam(const std::string &team)
{
    m_teams.push_back(team);
    zp::TeamManager::setTeamColor(team, zp::TeamManager::randomHue(team));
}

void zp::Map::clearAll()
{
    m_aliens.clear();
    m_rocks.clear();
    m_teams.clear();
    m_tiles.clear();
    m_size = {0, 0};
    m_timeUnitModifier = 1;
}
