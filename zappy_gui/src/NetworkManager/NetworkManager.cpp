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
    m_commands["pnw"] = std::bind(&NetworkManager::getNewPlayer, this, std::placeholders::_1, std::placeholders::_2);
    m_commands["sgt"] = std::bind(&NetworkManager::timeUnitRequest, this, std::placeholders::_1, std::placeholders::_2);
    m_commands["sst"] = std::bind(&NetworkManager::timeUnitModification, this, std::placeholders::_1, std::placeholders::_2);
    m_commands["ppo"] = std::bind(&NetworkManager::getPlayerPos, this, std::placeholders::_1, std::placeholders::_2);
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
    m_ip = ip;
    m_port = port;
    spdlog::info("Connected to remote server");
}

void zp::NetworkManager::update(std::unique_ptr<Map> &map)
{
    try {
        auto commands = receive();
        if (!commands->empty()) {
            for (auto &tokens : *commands) {
                if (m_commands.find(tokens[0]) != m_commands.end())
                    m_commands[tokens[0]](tokens, *map);
                else
                    spdlog::warn("Unknown command: {}", tokens[0]);
            }
        }
        updateMap(map);
        updatePlayers(map);
        updateRocks(map);
    } catch (const std::exception &e) {
        (void)e;
    }
}

void zp::NetworkManager::updateMap(std::unique_ptr<Map> &map)
{
    (void)map;
    std::size_t sent = 0;

    while (sent != 4)
        m_socket.send("mct\n" + sent, 4, sent);
}

void zp::NetworkManager::updatePlayers(std::unique_ptr<Map> &map)
{
    auto aliens = map->getAliens();
    std::size_t sent = 0;

    for (auto &alien : aliens) {
        std::string request = "ppo " + std::to_string(alien->getId()) + "\n";
        while (sent != request.size())
            m_socket.send(request.c_str() + sent, request.size(), sent);
    }
}

void zp::NetworkManager::updateRocks(std::unique_ptr<Map> &map)
{
    (void)map;
}

std::unique_ptr<std::vector<std::vector<std::string>>> zp::NetworkManager::receive()
{
    // char data[10240] = {0};
    // std::size_t size = 10240;
    // std::size_t received = 0;
    // sf::TcpSocket::Status status = m_socket.receive(data, size, received);

    // if (status == sf::TcpSocket::Disconnected || status == sf::TcpSocket::Error)
    //     throw std::runtime_error("Error: Cant receive message from remote server");
    // if (status == sf::TcpSocket::NotReady)
    //     return std::make_unique<std::vector<std::vector<std::string>>>();
    // if (received == 0)
    //     return std::make_unique<std::vector<std::vector<std::string>>>();
    // std::string str(data);
    // return zp::Utils::bigSplit(str, ' ');

    std::string receivedData;
    sf::TcpSocket::Status status;

    while (true)
    {
        char data[1024];
        std::size_t size = sizeof(data);
        std::size_t received = 0;

        status = m_socket.receive(data, size, received);

        if (status == sf::TcpSocket::Disconnected || status == sf::TcpSocket::Error)
            throw std::runtime_error("Error: Can't receive message from the remote server");

        receivedData += std::string(data, received);

        if (status == sf::TcpSocket::NotReady || received == 0)
            break; // Break if no more data or socket not ready
    }

    if (!receivedData.empty())
        return zp::Utils::bigSplit(receivedData, ' ');
    else
        return std::make_unique<std::vector<std::vector<std::string>>>();
}

void zp::NetworkManager::welcome(const std::vector<std::string> &tokens, Map &map)
{
    (void)tokens;
    (void)map;

    std::size_t sent = 0;

    while (sent != 8)
        m_socket.send("GRAPHIC\n" + sent, 8, sent);
}

void zp::NetworkManager::getMapSize(const std::vector<std::string> &tokens, Map &map)
{
    spdlog::info("Map size: {} {}", tokens[1], tokens[2]);
    map.setSize(std::stoi(tokens[1]), std::stoi(tokens[2]));
}

void zp::NetworkManager::getMapContent(const std::vector<std::string> &tokens, Map &map)
{
    if (tokens.size() != 10) {
        spdlog::warn("Received invalid number of tokens for mapContent");
        return;
    }
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

void zp::NetworkManager::getNewPlayer(const std::vector<std::string> &tokens, Map &map)
{
    std::shared_ptr<Alien> newAlien = std::make_shared<Alien>(sf::Vector2i(std::stoi(tokens[2]), std::stoi(tokens[3])), (zp::Direction)std::stoi(tokens[4]), tokens[6], std::stoi(tokens[1]));

    map.addAlien(newAlien);
    spdlog::info("getNewPlayer: {}", tokens[1]);
}

void zp::NetworkManager::getPlayerPos(const std::vector<std::string> &tokens, Map &map)
{
    auto aliens = map.getAliens();

    for (auto &alien : aliens) {
        if (alien->getId() == std::stoi(tokens[1])) {
            alien->setTilePosition(std::stoi(tokens[2]), std::stoi(tokens[3]));
            return;
        }
    }
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
