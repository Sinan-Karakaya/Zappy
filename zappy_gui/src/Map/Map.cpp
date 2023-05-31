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
}

void zp::Map::drawMap(sf::RenderTexture &window)
{
    for (int i = 0; i < m_size.x; i++) {
        for (int j = 0; j < m_size.y; j++) {
            m_tileSprite.setPosition(i * 64, j * 64);
            window.draw(m_tileSprite);
        }
    }
    for (auto &rock : m_rocks) {
        rock.draw(window);
    }
    for (auto &alien : m_aliens) {
        alien.draw(window);
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

std::shared_ptr<zp::Tile> zp::Map::getTile(int x, int y)
{
    return m_tiles[y * m_size.y + x];
}
