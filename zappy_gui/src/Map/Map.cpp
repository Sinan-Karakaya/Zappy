/*
** EPITECH PROJECT, 2023
** src/Map
** File description:
** Map
*/

#include "Map.hpp"

zp::Map::Map(int x, int y) : m_size(x, y)
{
    m_tiles.reserve(x * y);
    if (!m_tileTexture.loadFromFile(TILE_PATH)) {
        spdlog::error("Could not load texture");
        throw std::runtime_error("Could not load texture");
    }
    for (int i = 0; i < 7; i++) {
        m_rockTextures[i].loadFromImage(m_tileTexture.copyToImage(), sf::IntRect((i + 1) * 128, 0, 128, 128));
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

    for (int i = m_size.x; i > 0; i--) {
        for (int j = m_size.y - 1; j >= 0; j--) {
            m_tileSprite.setPosition((i - j) * TILE_WIDTH_HALF + 1920 / 2 + 48, (i + j) * (TILE_HEIGHT_HALF -
            TILE_ESCALATION) + 1080 / (m_size.y / 10));
            window.draw(m_tileSprite);
        }
    }
    for (auto &tile : m_tiles) {
        tile->draw(window);
    }
    for (auto &alien : m_aliens) {
        alien->draw(window);
    }
    for (auto &egg : m_eggs) {
        egg->draw(window);
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
        m_tiles.push_back(std::make_shared<zp::Tile>((sf::Vector2i){x, y}, (sf::Vector2i){i % x, i / x}, m_rockTextures));
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

const std::vector<std::shared_ptr<zp::IEntity>> &zp::Map::getAliens() const
{
    return m_aliens;
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
    m_eggs.clear();
    m_teams.clear();
    m_tiles.clear();
    m_size = {0, 0};
    m_timeUnitModifier = 1;
}

void zp::Map::addEgg(std::shared_ptr<zp::IEntity> egg)
{
    m_eggs.push_back(egg);
}

const std::vector<std::shared_ptr<zp::IEntity>> &zp::Map::getEggs() const
{
    return m_eggs;
}

void zp::Map::removeEgg(int id)
{
    for (auto it = m_eggs.begin(); it != m_eggs.end(); it++) {
        if ((*it)->getId() == id) {
            m_eggs.erase(it);
            return;
        }
    }
}
