/*
** EPITECH PROJECT, 2023
** src/Map
** File description:
** Tile
*/

#pragma once

#include <array>

namespace zp
{

enum Rocks {
    FOOD,
    LINEMATE,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME,
    NUM_OF_ROCKS
};

class Tile
{
public:
    Tile() { m_content.fill(0); }
    ~Tile() = default;

    void setRock(Rocks rock, int amount) { m_content[rock] = amount; }

private:
    std::array<int, NUM_OF_ROCKS> m_content;
};

} // zp
