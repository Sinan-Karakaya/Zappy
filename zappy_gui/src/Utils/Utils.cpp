/*
** EPITECH PROJECT, 2023
** src/Utils
** File description:
** Utils
*/

#include "Utils.hpp"

std::unique_ptr<std::vector<std::string>> zp::Utils::split(const std::string &s, char delim)
{
    std::unique_ptr<std::vector<std::string>> tokens;
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