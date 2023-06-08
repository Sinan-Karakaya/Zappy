/*
** EPITECH PROJECT, 2023
** src/Utils
** File description:
** Utils
*/

#include "Utils.hpp"

std::unique_ptr<std::vector<std::vector<std::string>>> zp::Utils::bigSplit(const std::string &s, char delim)
{
    auto commands = split(s, '\n');
    auto tokens = std::make_unique<std::vector<std::vector<std::string>>>();
    for (auto &e : *commands)
        tokens->push_back(*split(e, delim));
    return tokens;
}

std::unique_ptr<std::vector<std::string>> zp::Utils::split(const std::string &s, char delim)
{
    std::unique_ptr<std::vector<std::string>> tokens = std::make_unique<std::vector<std::string>>();
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delim))
        tokens->push_back(token);
    for (auto &e : *tokens)
        e = trim(e);
    return tokens;
}

std::string zp::Utils::trim(const std::string &s)
{
    auto wsfront = std::find_if_not(s.begin(), s.end(), [](int c) { return std::isspace(c); });
    auto wsback = std::find_if_not(s.rbegin(), s.rend(), [](int c) { return std::isspace(c); }).base();
    return (wsback <= wsfront ? std::string() : std::string(wsfront, wsback));
}

sf::Color zp::Utils::randomHue(const std::string &teamName)
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
