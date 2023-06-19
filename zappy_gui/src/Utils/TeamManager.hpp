/*
** EPITECH PROJECT, 2023
** src/Utils
** File description:
** TeamManager
*/

#pragma once

#include <string>
#include <vector>
#include <random>
#include <memory>
#include <sstream>
#include <unordered_map>

#include <SFML/Graphics.hpp>

namespace zp
{

    class TeamManager
    {
    public:
        TeamManager() = delete;
        ~TeamManager() = delete;

        static sf::Color randomHue(const std::string &teamName);
        static sf::Color getTeamColor(const std::string &teamName);
        static const std::unordered_map<std::string, sf::Color> &getTeamsColors();
        static void setTeamColor(const std::string &teamName, const sf::Color &color);

    private:
        inline static std::unordered_map<std::string, sf::Color> m_teamColors;

    };

} // zp
