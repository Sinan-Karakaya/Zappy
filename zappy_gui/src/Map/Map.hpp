/*
** EPITECH PROJECT, 2023
** src/Map
** File description:
** Map
*/

#pragma once

#include <vector>
#include <memory>

#include <spdlog/spdlog.h>
#include <SFML/Graphics.hpp>

#include "Entities/IEntity.hpp"
#include "Tile.hpp"

namespace zp
{

class Map
{
public:
    Map(int x = 0, int y = 0);
    ~Map() = default;

    void drawMap(sf::RenderTexture &window);
    void setSize(int x = 0, int y = 0);
    std::shared_ptr<Tile> getTile(int x, int y);

private:
    sf::Vector2i m_size = {0, 0};
    sf::Texture m_tileTexture;
    sf::Sprite m_tileSprite;

    std::vector<std::shared_ptr<Tile>> m_tiles;
    std::vector<zp::IEntity> m_rocks;
    std::vector<zp::IEntity> m_aliens;
};

} // zp
