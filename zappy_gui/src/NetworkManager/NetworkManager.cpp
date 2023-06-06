/*
** EPITECH PROJECT, 2023
** src/NetworkManager
** File description:
** NetworkManager
*/

#include "NetworkManager.hpp"

zp::NetworkManager::NetworkManager()
{
    m_commands["WELCOME"] = std::bind(&NetworkManager::welcome, this, std::placeholders::_1, std::placeholders::_2);
    m_commands["msz"] = std::bind(&NetworkManager::getMapSize, this, std::placeholders::_1, std::placeholders::_2);
    m_commands["bct"] = std::bind(&NetworkManager::getMapContent, this, std::placeholders::_1, std::placeholders::_2);
    m_commands["tna"] = std::bind(&NetworkManager::getNamesOfTeam, this, std::placeholders::_1, std::placeholders::_2);
    m_commands["pnw"] = std::bind(&NetworkManager::getPlayers, this, std::placeholders::_1, std::placeholders::_2);
    m_commands["sgt"] = std::bind(&NetworkManager::timeUnitRequest, this, std::placeholders::_1, std::placeholders::_2);
    m_commands["sst"] = std::bind(&NetworkManager::timeUnitModification, this, std::placeholders::_1, std::placeholders::_2);
}

zp::NetworkManager::~NetworkManager()
{
    m_socket.disconnect();
}

void zp::NetworkManager::connect(const std::string &ip, const std::string &port)
{
    if (m_socket.connect(sf::IpAddress(ip), std::stoi(port)) != sf::Socket::Done)
        throw std::runtime_error("Error: Cant connect to remote server");

    m_socket.setBlocking(false);
    spdlog::info("Connected to remote server");
}

void zp::NetworkManager::update(std::unique_ptr<Map> &map)
{
    try {
        auto commands = receive();
        if (commands->empty())
            return;
        for (auto &tokens : *commands) {
            if (m_commands.find(tokens[0]) != m_commands.end())
                m_commands[tokens[0]](tokens, *map);
            else
                spdlog::warn("Unknown command: {}", tokens[0]);
        }
    } catch (const std::exception &e) {
        (void)e;
    }
}

std::unique_ptr<std::vector<std::vector<std::string>>> zp::NetworkManager::receive()
{
    char data[10240] = {0};
    std::size_t size = 10240;
    std::size_t received;
    sf::TcpSocket::Status status = m_socket.receive(data, size, received);
    if (status == sf::TcpSocket::Disconnected || status == sf::TcpSocket::Error)
        throw std::runtime_error("Error: Cant receive message from remote server");
    if (status == sf::TcpSocket::NotReady)
        return std::make_unique<std::vector<std::vector<std::string>>>();
    if (received == 0)
        return std::make_unique<std::vector<std::vector<std::string>>>();
    std::string str(data);
    return zp::Utils::bigSplit(str, ' ');
}

void zp::NetworkManager::welcome(const std::vector<std::string> &tokens, Map &map)
{
    (void)tokens;
    (void)map;
    m_socket.send("GRAPHIC\n", 8);
}

void zp::NetworkManager::getMapSize(const std::vector<std::string> &tokens, Map &map)
{
    spdlog::info("Map size: {} {}", tokens[1], tokens[2]);
    map.setSize(std::stoi(tokens[1]), std::stoi(tokens[2]));
}

void zp::NetworkManager::getMapContent(const std::vector<std::string> &tokens, Map &map)
{
    try {
        auto tile = map.getTile(std::stoi(tokens[1]), std::stoi(tokens[2]));
        tile->setRock(FOOD, std::stoi(tokens[3]));
        tile->setRock(LINEMATE, std::stoi(tokens[4]));
        tile->setRock(DERAUMERE, std::stoi(tokens[5]));
        tile->setRock(SIBUR, std::stoi(tokens[6]));
        tile->setRock(MENDIANE, std::stoi(tokens[7]));
        tile->setRock(PHIRAS, std::stoi(tokens[8]));
        tile->setRock(THYSTAME, std::stoi(tokens[9]));
    } catch (const std::exception &e) {
        spdlog::error("Error: Out of range: {}", e.what());
    }
}

void zp::NetworkManager::getNamesOfTeam(const std::vector<std::string> &tokens, Map &map)
{
    (void)map;
    spdlog::info("getNamesOfTeam: {}", tokens[1]);
}

void zp::NetworkManager::getPlayers(const std::vector<std::string> &tokens, Map &map)
{
    (void)map;
    (void)tokens;
}

void zp::NetworkManager::getPlayer(int id)
{
    (void)id;
}

void zp::NetworkManager::timeUnitRequest(const std::vector<std::string> &tokens, Map &map)
{
    (void)map;
    spdlog::info("timeUnitRequest: {}", tokens[1]);
}

void zp::NetworkManager::timeUnitModification(const std::vector<std::string> &tokens, Map &map)
{
    (void)map;
    (void)tokens;
}
