/*
** EPITECH PROJECT, 2023
** src/Entities
** File description:
** Rock
*/

#pragma once

#include "IEntity.hpp"
#include "Utils/Utils.hpp"
#include "Utils/RockManager.hpp"

#define TILE_WIDTH_HALF 32
#define TILE_HEIGHT_HALF 32
#define TILE_ESCALATION 12
#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080

namespace zp
{

class Rock
{
public:
    Rock() = default;
    Rock(const Rock &rock) = default;
    ~Rock() = default;

    /**
     * @brief Draw the rock on the floor
     * @param window
     */
    void draw(sf::RenderTexture &window);

    /**
     * @brief Set the data of the rock this way since we can only use the default constructor inside an array
     * @param mapSize Size of the map in tiles
     * @param tilePos Position of the tile in the map
     * @param rockId ID of the rock
     * @param rockTexture Texture of the rock to use
     */
    void setData(sf::Vector2i mapSize, sf::Vector2i tilePos, int rockId, sf::Texture &rockTexture);

private:
    sf::Vector2i m_tilePosition = {0, 0};
    sf::Vector2i m_mapSize = {0, 0};
    sf::Vector2f m_position = {0, 0};
    sf::Sprite m_sprite;
    int m_rockId = 0;
};

} // zp
