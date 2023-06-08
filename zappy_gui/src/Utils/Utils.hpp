/*
** EPITECH PROJECT, 2023
** src/Utils
** File description:
** Utils
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
    class Utils {
    public:
        Utils() = delete;
        ~Utils() = delete;

        static std::unique_ptr<std::vector<std::vector<std::string>>> bigSplit(const std::string &s, char
        delim);
        static std::unique_ptr<std::vector<std::string>> split(const std::string &s, char delim);
        static std::string trim(const std::string &s);

        static sf::Color randomHue(const std::string &teamName);

    private:
        inline static std::unordered_map<std::string, sf::Color> m_teamColors;
    };
} // zp
