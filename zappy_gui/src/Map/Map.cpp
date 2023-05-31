/*
** EPITECH PROJECT, 2023
** src/Map
** File description:
** Map
*/

#include "Map.hpp"

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
    m_size.x = x;
    m_size.y = y;
}
