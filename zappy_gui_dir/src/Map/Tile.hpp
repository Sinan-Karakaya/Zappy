/*
** EPITECH PROJECT, 2023
** src/Map
** File description:
** Tile
*/

#pragma once

#include <array>

#include "Utils/RocksType.hpp"
#include "Entities/Rock.hpp"

namespace zp
{

class Tile
{
public:
    Tile(sf::Vector2i mapSize, sf::Vector2i tilePosition, std::array<sf::Texture, 7> &m_textures);
    ~Tile() = default;

    /**
     * @brief Set the rock amount of this tile
     * @param rock Type of rock to set quantity of
     * @param amount Amount of rock to set
     */
    void setRock(Rocks rock, int amount) { m_content[rock] = amount; }

    /**
     * @brief Get the rock amount of this tile for every type
     * @return Amount of rock
     */
    const std::array<int, NUM_OF_ROCKS> &getRessources() const { return m_content; }

    /**
     * @brief Draw the tile(e.g the rocks on the tile) on the floor
     * @param window
     */
    void draw(sf::RenderTexture &window);

private:
    std::array<int, NUM_OF_ROCKS> m_content = {0, 0, 0, 0, 0, 0, 0};
    std::array<zp::Rock, NUM_OF_ROCKS> m_rocks;

    sf::Vector2i m_mapSize = {0, 0};
    sf::Vector2i m_tilePosition = {0, 0};
};

} // zp
