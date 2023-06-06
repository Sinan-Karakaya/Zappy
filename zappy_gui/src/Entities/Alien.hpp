/*
** EPITECH PROJECT, 2023
** src/Entities
** File description:
** Alien
*/

#pragma once

#include "IEntity.hpp"

#define ALIEN_PATH "assets/sprites/zeologue.png"

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
