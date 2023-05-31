/*
** EPITECH PROJECT, 2023
** src/Map
** File description:
** Map
*/

#pragma once

#include <vector>

#include <SFML/Graphics.hpp>

#include "Entities/IEntity.hpp"

namespace zp
{

class Map
{
public:
    explicit Map(int x = 0, int y = 0) : m_size(x, y) {}
    ~Map() = default;

    void drawMap(sf::RenderTexture &window);
    void setSize(int x = 0, int y = 0);

private:
    sf::Vector2i m_size = {0, 0};
    sf::Texture m_tileTexture;
    sf::Sprite m_tileSprite;

    std::vector<zp::IEntity> m_rocks;
    std::vector<zp::IEntity> m_aliens;
};

} // zp
