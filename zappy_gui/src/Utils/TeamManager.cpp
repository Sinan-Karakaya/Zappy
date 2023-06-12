/*
** EPITECH PROJECT, 2023
** src/Utils
** File description:
** TeamManager
*/

#include "TeamManager.hpp"

sf::Color zp::TeamManager::randomHue(const std::string &teamName)
{
    if (m_teamColors.find(teamName) != m_teamColors.end())
        return m_teamColors[teamName];

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 255);

    const int hue = dis(gen);  // Generate a random hue value

    // Convert HSV to RGB
    const float saturation = 1.0f;
    const float value = 1.0f;

    const float chroma = value * saturation;
    const float huePrime = hue / 60.0f;
    const float x = chroma * (1 - std::abs(std::fmod(huePrime, 2) - 1));

    float red = 0, green = 0, blue = 0;

    if (huePrime >= 0 && huePrime < 1) {
        red = chroma;
        green = x;
    } else if (huePrime >= 1 && huePrime < 2) {
        red = x;
        green = chroma;
    } else if (huePrime >= 2 && huePrime < 3) {
        green = chroma;
        blue = x;
    } else if (huePrime >= 3 && huePrime < 4) {
        green = x;
        blue = chroma;
    } else if (huePrime >= 4 && huePrime < 5) {
        red = x;
        blue = chroma;
    } else if (huePrime >= 5 && huePrime < 6) {
        red = chroma;
        blue = x;
    }

    const float m = value - chroma;
    red += m;
    green += m;
    blue += m;

    // Convert floating-point color values to integers (0-255)
    const int r = static_cast<int>(red * 255);
    const int g = static_cast<int>(green * 255);
    const int b = static_cast<int>(blue * 255);

    m_teamColors[teamName] = sf::Color(r, g, b);
    return sf::Color(r, g, b);
}

sf::Color zp::TeamManager::getTeamColor(const std::string &teamName)
{
    if (m_teamColors.find(teamName) != m_teamColors.end())
        return m_teamColors[teamName];
    else
        return sf::Color(255, 0, 255);
}

const std::unordered_map<std::string, sf::Color> &zp::TeamManager::getTeamsColors()
{
    return m_teamColors;
}

void zp::TeamManager::setTeamColor(const std::string &teamName, const sf::Color &color)
{
    m_teamColors[teamName] = color;
}
