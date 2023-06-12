/*
** EPITECH PROJECT, 2023
** src/Entities
** File description:
** Alien
*/

#pragma once

#include "IEntity.hpp"
#include "Utils/Utils.hpp"
#include "Utils/TeamManager.hpp"

#define ALIEN_PATH "assets/sprites/zeologue.png"
#define ALIEN_HEIGHT 84
#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080
#define TILE_WIDTH_HALF 32
#define TILE_ESCALATION 8

namespace zp
{

class Alien : public IEntity
{
public:
    Alien() = default;
    Alien(const Alien &alien) = default;
    Alien(sf::Vector2i tilePos, Direction dir, const std::string &teamName, int id = -1);
    ~Alien() override = default;

    void draw(sf::RenderTexture &window) override;
    void setTilePosition(int x, int y) override;
    void setDirection(Direction dir) override;
    int getId() const override { return m_id; }
};

} // zp
