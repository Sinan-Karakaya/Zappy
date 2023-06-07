/*
** EPITECH PROJECT, 2023
** src/Entities
** File description:
** Alien
*/

#pragma once

#include "IEntity.hpp"

namespace zp
{

class Alien : public IEntity
{
public:
    Alien() = default;
    Alien(const Alien &alien) = default;
    Alien(sf::Vector2i pos, sf::Vector2i tilePos, Direction dir, const std::string &teamName);
    ~Alien() override = default;

    void draw(sf::RenderTexture &window) override;
    void setTilePosition(int x, int y) override;
    void setDirection(Direction dir) override;
//    void writeToChat(Chat &chat) override;
};

} // zp
