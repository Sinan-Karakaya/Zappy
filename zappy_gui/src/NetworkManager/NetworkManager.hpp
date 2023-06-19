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
#include <algorithm>
#include <deque>

#include <spdlog/spdlog.h>
#include <SFML/Network.hpp>

#include "Utils/Utils.hpp"
#include "Map/Map.hpp"
#include "Entities/Alien.hpp"
#include "Entities/Egg.hpp"
#include "Socket/Socket.hpp"
#include "Chat/Chat.hpp"

namespace zp
{

class NetworkManager
{
public:
    /**
     * @brief Construct a new Network Manager object with a reference to the chat instance required for broadcasting
     * @param chat chat to hold reference of
     */
    NetworkManager(Chat &chat, bool &isConnected);
    ~NetworkManager();

    /**
     * @brief Connect to the server
     * @param port
     * @param ip Default to localhost
     */
    void connect(const std::string &port, const std::string &ip = "127.0.0.1");

    /**
     * @brief Update the map with the data received from the server
     * @param map Map to be updated
     */
    void update(std::unique_ptr<Map> &map);

    /**
     * @brief Add a message to the queue
     * @param message message to add
     */
    static void addMessage(const std::string &message) { m_messageQueue.push_back(message); }

    /**
     * @brief Send the message to the networkManager to attempt connecting to the server
     */
     static void connectionInfos(const std::string &ip, const std::string &port) { m_connectionAwaiting = {ip, port}; }

private:
    /**
     * @brief Disconnect from the server and clear all left over data
     */
     void disconnect(Map &map, Chat &chat);

    /**
     * @brief Update the map with the data received from the server
     * @param map Map to update
     */
    void updateMap(std::unique_ptr<Map> &map);

    /**
     * @brief Update the players on the map
     * @param map Map on which the players should be updated
     */
    void updatePlayers(std::unique_ptr<Map> &map);

    /**
     * @brief Update the rocks on the map
     * @param map Map on which the rocks should be updated
     */
    void updateRocks(std::unique_ptr<Map> &map);

    /**
     * @brief Handle the welcome command, send "GRAPHIC" to the server
     * @param tokens Vector of the response
     * @param map map to updateq
     */
    void welcome(const std::vector<std::string> &tokens, Map &map);

    /**
     * @brief Handle response from msz
     * @param tokens Vector of the response
     * @param map map to update
     */
    void getMapSize(const std::vector<std::string> &tokens, Map &map);

    /**
     * @brief Handle response from bct
     * @param tokens Vector of the responsee
     * @param map map to update
     */
    void getMapContent(const std::vector<std::string> &tokens, Map &map);

    /**
     * @brief Handle response from tna
     * @param tokens Vector of the response
     * @param map map to update
     */
    void getNamesOfTeam(const std::vector<std::string> &tokens, Map &map);

    /**
     * @brief Handle response from pnw
     * @param tokens Vector of the response
     * @param map map to update
     */
    void getNewPlayer(const std::vector<std::string> &tokens, Map &map);

    /**
     * @brief Handle response from ppo
     * @param tokens Vector of the response
     * @param map map to update
     */
    void getPlayerPos(const std::vector<std::string> &tokens, Map &map);

    /**
     * @brief Handle response from plv
     * @param tokens Vector of the response
     * @param map map to update
     */
    void timeUnitRequest(const std::vector<std::string> &tokens, Map &map);

    /**
     * @brief Handle response from pin
     * @param tokens Vector of the response
     * @param map map to update
     */
    void timeUnitModification(const std::vector<std::string> &tokens, Map &map);

    /**
     * @brief Handle incoming broadcast
     * @param tokens Vector of the response
     * @param map map to update
     */
    void broadCast(const std::vector<std::string> &tokens, Map &map);

    /**
     * @brief Remove a player due to death or disconnection
     * @param tokens Vector of the response
     * @param map map to update
     */
    void removePlayer(const std::vector<std::string> &tokens, Map &map);

    /**
     * @brief Handle incoming inventory
     * @param tokens Vector of the response
     * @param map map to update
     */
    void setInventory(const std::vector<std::string> &tokens, Map &map);

    /**
     * @brief Handle eggs being laid
     * @param tokens Vector of the response
     * @param map map to update
     */
    void eggLaid(const std::vector<std::string> &tokens, Map &map);

    /**
     * @brief Handle eggs death
     * @param tokens Vector of the response
     * @param map map to update
     */
    void removeEgg(const std::vector<std::string> &tokens, Map &map);

    /**
     * @brief Handle eggs hatching
     * @param tokens Vector of the response
     * @param map map to update
     */
    void eggHatched(const std::vector<std::string> &tokens, Map &map);

    /**
     * @brief For commands I don't care about for now
     * @param tokens Vector of the response
     * @param map map to update
     */
    void doNothing(const std::vector<std::string> &tokens, Map &map);

    /**
     * @brief Get the start of the incantation of multiple aliens
     * @param tokens Vector of the response
     * @param map map to update
     */
    void getIncantationStart(const std::vector<std::string> &tokens, Map &map);

    /**
     * @brief Get the end of the incantation of multiple aliens
     * @param tokens Vector of the response
     * @param map map to update
     */
    void getIncantationEnd(const std::vector<std::string> &tokens, Map &map);

private:
    zp::Socket m_socket;
    std::string m_port;
    std::string m_ip;

    std::unordered_map<std::string, std::function<void(const std::vector<std::string> &tokens, Map &map)>> m_commands;

    Chat &m_chat;
    bool &m_isConnected;
    inline static std::deque<std::string> m_messageQueue;
    inline static std::pair<std::string, std::string> m_connectionAwaiting;
};

} // zp
