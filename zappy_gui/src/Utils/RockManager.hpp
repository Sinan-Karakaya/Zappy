/*
** EPITECH PROJECT, 2023
** zappy_gui
** File description:
** RockManager
*/

#pragma once

#include <string>
#include <vector>
#include <random>
#include <unordered_map>

#include <SFML/Graphics.hpp>

namespace zp
{

    class RockManager
    {
    public:
        RockManager() = delete;
        ~RockManager() = delete;

        static sf::Color randomColor(int rockId);
        static void setRockColor(int rockId, const sf::Color &color) { m_rockColors[rockId] = color; }
        static const std::unordered_map<int, sf::Color> &getRockColors() { return m_rockColors; }

    private:
        inline static std::unordered_map<int, sf::Color> m_rockColors;
    };

} // zp
