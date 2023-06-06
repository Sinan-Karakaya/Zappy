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

#define TILE_PATH "assets/sprites/floor_zappy.png"
#define TILE_WIDTH_HALF 32
#define TILE_HEIGHT_HALF 32

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

    void addAlien(std::shared_ptr<zp::IEntity> alien);
    void addRock(std::shared_ptr<zp::IEntity> rock);

    std::vector<std::shared_ptr<zp::IEntity>> &getAliens();
    std::vector<std::shared_ptr<zp::IEntity>> &getRocks();

private:
    sf::Vector2i m_size = {0, 0};
    sf::Texture m_tileTexture;
    sf::Sprite m_tileSprite;

    std::vector<std::shared_ptr<Tile>> m_tiles;
    std::vector<std::shared_ptr<zp::IEntity>> m_rocks;
    std::vector<std::shared_ptr<zp::IEntity>> m_aliens;
};

} // zp
