/*
** EPITECH PROJECT, 2023
** src/Entities
** File description:
** Rock
*/

#pragma once

#include "IEntity.hpp"

namespace zp
{

class Rock : public IEntity
{
public:
    Rock() = default;
    Rock(const Rock &rock) = default;
    Rock(sf::Vector2i pos, sf::Vector2i tilePos, Direction dir, const std::string &teamName);
    ~Rock() override = default;

    void draw(sf::RenderTexture &window) override;
    void setTilePosition(int x, int y) override;
    void setDirection(Direction dir) override;
};

} // zp