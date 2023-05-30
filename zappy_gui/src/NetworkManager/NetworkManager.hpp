/*
** EPITECH PROJECT, 2023
** src/NetworkManager
** File description:
** NetworkManager
*/

#pragma once

#include <string>
#include <vector>
#include <exception>
#include <unordered_map>
#include <functional>

#include <spdlog/spdlog.h>
#include <SFML/Network.hpp>

#include "Utils/Utils.hpp"

namespace zp
{

class NetworkManager
{
public:
    NetworkManager();
    ~NetworkManager() = default;

    void connect(const std::string &ip = "127.0.0.1", const std::string &port = "4242");
    void update();

private:
    const std::vector<std::string> &receive();
    void welcome(const std::vector<std::string> &tokens);
    void getMapSize(const std::vector<std::string> &tokens);
    void getMapContent(const std::vector<std::string> &tokens);
    void getNamesOfTeam(const std::vector<std::string> &tokens);
    void getPlayers(const std::vector<std::string> &tokens);
    void getPlayer(int id);
    void timeUnitRequest(const std::vector<std::string> &tokens);
    void timeUnitModification(const std::vector<std::string> &tokens);

private:
    sf::TcpSocket m_socket;

    std::unordered_map<std::string, std::function<void(const std::vector<std::string> &tokens)>> m_commands;
};

} // zp
