/*
** EPITECH PROJECT, 2023
** src/NetworkManager
** File description:
** NetworkManager
*/

#include "NetworkManager.hpp"

zp::NetworkManager::NetworkManager(Chat &chat, bool &isConnected)
    : m_chat(chat), m_isConnected(isConnected)
{
    m_commands["WELCOME"] = std::bind(&NetworkManager::welcome, this, std::placeholders::_1, std::placeholders::_2);
    m_commands["msz"] = std::bind(&NetworkManager::getMapSize, this, std::placeholders::_1, std::placeholders::_2);
    m_commands["bct"] = std::bind(&NetworkManager::getMapContent, this, std::placeholders::_1, std::placeholders::_2);
    m_commands["tna"] = std::bind(&NetworkManager::getNamesOfTeam, this, std::placeholders::_1, std::placeholders::_2);
    m_commands["pnw"] = std::bind(&NetworkManager::getNewPlayer, this, std::placeholders::_1, std::placeholders::_2);
    m_commands["sgt"] = std::bind(&NetworkManager::timeUnitRequest, this, std::placeholders::_1, std::placeholders::_2);
    m_commands["sst"] = std::bind(&NetworkManager::timeUnitModification, this, std::placeholders::_1, std::placeholders::_2);
    m_commands["ppo"] = std::bind(&NetworkManager::getPlayerPos, this, std::placeholders::_1, std::placeholders::_2);
    m_commands["pbc"] = std::bind(&NetworkManager::broadCast, this, std::placeholders::_1, std::placeholders::_2);
    m_commands["pgt"] = std::bind(&NetworkManager::doNothing, this, std::placeholders::_1, std::placeholders::_2);
    m_commands["suc"] = std::bind(&NetworkManager::doNothing, this, std::placeholders::_1, std::placeholders::_2);
    m_commands["sbp"] = std::bind(&NetworkManager::doNothing, this, std::placeholders::_1, std::placeholders::_2);
    m_commands["pdr"] = std::bind(&NetworkManager::doNothing, this, std::placeholders::_1, std::placeholders::_2);
    m_commands["plv"] = std::bind(&NetworkManager::doNothing, this, std::placeholders::_1, std::placeholders::_2);
    m_commands["pin"] = std::bind(&NetworkManager::setInventory, this, std::placeholders::_1, std::placeholders::_2);
    m_commands["pex"] = std::bind(&NetworkManager::removePlayer, this, std::placeholders::_1, std::placeholders::_2);
    m_commands["pdi"] = std::bind(&NetworkManager::removePlayer, this, std::placeholders::_1, std::placeholders::_2);
    m_commands["enw"] = std::bind(&NetworkManager::eggLaid, this, std::placeholders::_1, std::placeholders::_2);
    m_commands["edi"] = std::bind(&NetworkManager::removeEgg, this, std::placeholders::_1, std::placeholders::_2);
    m_commands["ebo"] = std::bind(&NetworkManager::eggHatched, this, std::placeholders::_1, std::placeholders::_2);
}

zp::NetworkManager::~NetworkManager()
{
    m_socket.disconnect();
    m_isConnected = false;
}

void zp::NetworkManager::connect(const std::string &ip, const std::string &port)
{
    if (port.empty() || ip.empty())
        return;
    try {
        m_socket.connect(port, ip);
        m_ip = ip;
        m_port = port;
        m_isConnected = true;
        spdlog::info("Connected to remote server");
    } catch (const std::runtime_error &e) {
        throw e;
    }
}

void zp::NetworkManager::update(std::unique_ptr<Map> &map)
{
    if (!m_isConnected) {
        if (!m_connectionAwaiting.first.empty() && !m_connectionAwaiting.second.empty()) {
            connect(m_connectionAwaiting.first, m_connectionAwaiting.second);
            m_connectionAwaiting.first.clear();
            m_connectionAwaiting.second.clear();
        }
        return;
    }
    try {
        m_socket.update();
        if (m_socket.isReadyToRead()) {
            auto commands = m_socket.receive();
            if (commands) {
                if (commands->begin()->empty())
                    commands->erase(commands->begin());
                for (auto &tokens: *commands) {
                    if (m_commands.find(tokens[0]) != m_commands.end())
                        m_commands[tokens[0]](tokens, *map);
                    else
                        spdlog::warn("Unknown command: {}", tokens[0]);
                }
            }
        }
        if (m_socket.isReadyToWrite()) {
            updateMap(map);
            updatePlayers(map);
            for (auto &message : m_messageQueue) {
                if (message == "quit\n") {
                    disconnect(*map, m_chat);
                    return;
                }
                m_socket.send(message);
                m_messageQueue.pop_front();
            }
        }
    } catch (const std::runtime_error &e) {
        spdlog::error("{}", e.what());
        throw std::runtime_error("Lost connection to server");
    } catch (const std::exception &e) {
        spdlog::error("{}", e.what());
        throw std::runtime_error("Something bad happened when updating with the server");
    }
}

void zp::NetworkManager::updateMap(std::unique_ptr<Map> &map)
{
    (void)map;
    m_socket.send("mct\n");
}

void zp::NetworkManager::updatePlayers(std::unique_ptr<Map> &map)
{
    auto aliens = map->getAliens();

    for (auto &alien : aliens) {
        std::string request = "ppo " + std::to_string(alien->getId()) + "\n";
        m_socket.send(request);
        request = "pin " + std::to_string(alien->getId()) + "\n";
        m_socket.send(request);
    }
}

void zp::NetworkManager::welcome(const std::vector<std::string> &tokens, Map &map)
{
    (void)tokens;
    (void)map;
    m_socket.send("GRAPHIC\n");
}

void zp::NetworkManager::getMapSize(const std::vector<std::string> &tokens, Map &map)
{
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
    if (tokens[1] != "GRAPHIC")
        map.addTeam(tokens[1]);
}

void zp::NetworkManager::getNewPlayer(const std::vector<std::string> &tokens, Map &map)
{
    try {
        std::shared_ptr<Alien> newAlien = std::make_shared<Alien>(
                sf::Vector2i(std::stoi(tokens[2]), std::stoi(tokens[3])),
                (zp::Direction) std::stoi(tokens[4]), tokens[6], std::stoi(tokens[1]));
        spdlog::info("New player: {}", tokens[1]);
        map.addAlien(newAlien);
    } catch (const std::exception &e) {
        spdlog::error("Exception thrown on alien creation", e.what());
        return;
    }
}

void zp::NetworkManager::getPlayerPos(const std::vector<std::string> &tokens, Map &map)
{
    if (tokens.size() != 5) {
        spdlog::warn("Received invalid number of tokens for ppo");
        return;
    }
    auto aliens = map.getAliens();

    for (auto &alien : aliens) {
        if (alien->getId() == std::stoi(tokens[1])) {
            alien->setTilePosition(std::stoi(tokens[2]) + 1, std::stoi(tokens[3]) + 1, 1080 / (map.getSize().y / 10));
            alien->setDirection((zp::Direction) std::stoi(tokens[4]));
            return;
        }
    }
}

void zp::NetworkManager::timeUnitRequest(const std::vector<std::string> &tokens, Map &map)
{
    (void)map;
    map.setTimeUnitModifier(std::stoi(tokens[1]));
}

void zp::NetworkManager::timeUnitModification(const std::vector<std::string> &tokens, Map &map)
{
    (void)tokens;
    map.setTimeUnitModifier(std::stoi(tokens[1]));
}

void zp::NetworkManager::broadCast(const std::vector<std::string> &tokens, zp::Map &map)
{
    (void)map;
    std::string message = tokens[2];
    for (size_t i = 3; i < tokens.size(); i++)
        message += " " + tokens[i];

    m_chat.addMessage(tokens[1], message);
}

void zp::NetworkManager::doNothing(const std::vector<std::string> &tokens, zp::Map &map)
{
    (void)map;
    (void)tokens;
}

void zp::NetworkManager::removePlayer(const std::vector<std::string> &tokens, zp::Map &map)
{
    auto aliens = map.getAliens();

    for (auto &alien : aliens) {
        if (alien->getId() == std::stoi(tokens[1])) {
            map.removeAlien(std::stoi(tokens[1]));
            return;
        }
    }
}

void zp::NetworkManager::setInventory(const std::vector <std::string> &tokens, zp::Map &map)
{
    if (tokens.size() != 11) {
        spdlog::warn("Received invalid number of tokens for pin");
        return;
    }
    auto players = map.getAliens();
    std::shared_ptr<IEntity> target = nullptr;

    for (auto &player : players) {
        if (player->getId() == std::stoi(tokens[1])) {
            target = player;
            break;
        }
    }
    if (target == nullptr) {
        spdlog::warn("Received inventory for unknown player");
        return;
    }
    for (size_t i = 4; i < tokens.size(); i++) {
        target->setRockQuantity((zp::Rocks)(i - 4), std::stoi(tokens[i]));
    }
}

void zp::NetworkManager::disconnect(Map &map, Chat &chat)
{
    m_socket.disconnect();
    m_isConnected = false;
    m_messageQueue.clear();
    map.clearAll();
    chat.clearMessages();
}

void zp::NetworkManager::eggLaid(const std::vector<std::string> &tokens, zp::Map &map)
{
    if (tokens.size() != 5) {
        spdlog::warn("Received invalid number of tokens for enw");
        return;
    }

    spdlog::info("Egg laid by player {}", tokens[1]);
    auto aliens = map.getAliens();
    std::shared_ptr<IEntity> laider = nullptr;
    for (auto &alien : aliens) {
        if (alien->getId() == std::stoi(tokens[1])) {
            laider = alien;
            break;
        }
    }
    if (!laider) {
        spdlog::warn("Received egg laid for unknown player");
        return;
    }
    sf::Vector2i tilePos = sf::Vector2i(std::stoi(tokens[3]), std::stoi(tokens[4]));
    std::shared_ptr<Egg> egg = std::make_shared<Egg>(tilePos, WEST, laider->getTeamName(), std::stoi(tokens[1]));
    egg->setTilePosition(tilePos.x, tilePos.y, 1080 / (map.getSize().y / 10));
    map.addEgg(egg);
}

void zp::NetworkManager::removeEgg(const std::vector<std::string> &tokens, zp::Map &map)
{
    if (tokens.size() != 2) {
        spdlog::warn("Received invalid number of tokens for eht");
        return;
    }
    map.removeEgg(std::stoi(tokens[1]));
}

void zp::NetworkManager::eggHatched(const std::vector<std::string> &tokens, zp::Map &map)
{
    if (tokens.size() != 2) {
        spdlog::warn("Received invalid number of tokens for eht");
        return;
    }
    auto eggs = map.getEggs();
    std::shared_ptr<IEntity>  eggTarget = nullptr;
    for (auto &egg : eggs) {
        if (egg->getId() == std::stoi(tokens[1])) {
            eggTarget = egg;
            break;
        }
    }
    if (!eggTarget) {
        spdlog::warn("Received egg hatched for unknown egg");
        return;
    }
    map.removeEgg(std::stoi(tokens[1]));

}
