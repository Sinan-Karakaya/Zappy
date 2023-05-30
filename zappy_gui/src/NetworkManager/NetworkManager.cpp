/*
** EPITECH PROJECT, 2023
** src/NetworkManager
** File description:
** NetworkManager
*/

#include "NetworkManager.hpp"

zp::NetworkManager::NetworkManager()
{
    m_commands["WELCOME"] = std::bind(&NetworkManager::welcome, this, std::placeholders::_1);
    m_commands["msz"] = std::bind(&NetworkManager::getMapSize, this, std::placeholders::_1);
    m_commands["bct"] = std::bind(&NetworkManager::getMapContent, this, std::placeholders::_1);
    m_commands["tna"] = std::bind(&NetworkManager::getNamesOfTeam, this, std::placeholders::_1);
    m_commands["pnw"] = std::bind(&NetworkManager::getPlayers, this, std::placeholders::_1);
    m_commands["sgt"] = std::bind(&NetworkManager::timeUnitRequest, this, std::placeholders::_1);
    m_commands["sst"] = std::bind(&NetworkManager::timeUnitModification, this, std::placeholders::_1);
}

void zp::NetworkManager::connect(const std::string &ip, const std::string &port)
{
    if (m_socket.connect(sf::IpAddress(ip), std::stoi(port)) != sf::Socket::Done)
        throw std::runtime_error("Error: Cant connect to remote server");

    m_socket.setBlocking(false);
    spdlog::info("Connected to remote server");
}

void zp::NetworkManager::update()
{
    try {
        auto tokens = receive();
        if (tokens.empty())
            return;
        if (m_commands.find(tokens[0]) != m_commands.end())
            m_commands[tokens[0]](tokens);
        else
            spdlog::warn("Unknown command: {}", tokens[0]);
    } catch (const std::exception &e) {
        (void)e;
    }
}

const std::vector<std::string> &zp::NetworkManager::receive()
{
    char data[1024] = {0};
    std::size_t size = 1024;
    std::size_t received;
    if (m_socket.receive(data, size, received) != sf::Socket::Done)
        throw std::runtime_error("Error: Cant receive message from remote server");
    std::string str(data);
    return zp::Utils::split(str, ' ');
}

void zp::NetworkManager::welcome(const std::vector<std::string> &tokens)
{
    (void)tokens;
    m_socket.send("GRAPHIC\n", 8);
}

void zp::NetworkManager::getMapSize(const std::vector<std::string> &tokens)
{
    spdlog::info("Map size: {} {}", tokens[1], tokens[2]);
}

void zp::NetworkManager::getMapContent(const std::vector<std::string> &tokens)
{
    spdlog::info("GetMapContent: {}", tokens[1]);
}

void zp::NetworkManager::getNamesOfTeam(const std::vector<std::string> &tokens)
{
    spdlog::info("getNamesOfTeam: {}", tokens[1]);
}

void zp::NetworkManager::getPlayers(const std::vector<std::string> &tokens)
{
    (void)tokens;
}

void zp::NetworkManager::getPlayer(int id)
{
    (void)id;
}

void zp::NetworkManager::timeUnitRequest(const std::vector<std::string> &tokens)
{
    spdlog::info("timeUnitRequest: {}", tokens[1]);
}

void zp::NetworkManager::timeUnitModification(const std::vector<std::string> &tokens)
{
    (void)tokens;
}
