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
#include "Map/Map.hpp"

namespace zp
{

class NetworkManager
{
public:
    NetworkManager();
    ~NetworkManager();

    void connect(const std::string &port, const std::string &ip = "127.0.0.1");
    void update(std::unique_ptr<Map> &map);

private:
    std::unique_ptr<std::vector<std::vector<std::string>>> receive();
    void welcome(const std::vector<std::string> &tokens, Map &map);
    void getMapSize(const std::vector<std::string> &tokens, Map &map);
    void getMapContent(const std::vector<std::string> &tokens, Map &map);
    void getNamesOfTeam(const std::vector<std::string> &tokens, Map &map);
    void getPlayers(const std::vector<std::string> &tokens, Map &map);
    void getPlayer(int id);
    void timeUnitRequest(const std::vector<std::string> &tokens, Map &map);
    void timeUnitModification(const std::vector<std::string> &tokens, Map &map);

private:
    sf::TcpSocket m_socket;
    std::string m_port;
    std::string m_ip;

    std::unordered_map<std::string, std::function<void(const std::vector<std::string> &tokens, Map &map)>> m_commands;
};

} // zp
