/*
** EPITECH PROJECT, 2023
** zappy_gui
** File description:
** Tile
*/

#include "Tile.hpp"

zp::Tile::Tile(sf::Vector2i mapSize, sf::Vector2i tilePosition, std::array<sf::Texture, 7> &m_textures)
    : m_mapSize(mapSize), m_tilePosition(tilePosition)
{
    for (int idx = 0; auto &rock : m_rocks) {
        rock.setData(m_mapSize, m_tilePosition, idx, m_textures[idx]);
        idx++;
    }
}

void zp::Tile::draw(sf::RenderTexture &window)
{
    for (auto &rock : m_rocks) {
        if (m_content[&rock - &m_rocks[0]] == 0)
            continue;
        rock.draw(window);
    }
}
