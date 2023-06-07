/*
** EPITECH PROJECT, 2023
** project (Workspace) [WSL: Ubuntu-22.04]
** File description:
** Socket
*/

#pragma once

#include <iostream>
#include <exception>
#include <memory>
#include <string>
#include <vector>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#include <spdlog/spdlog.h>

#include "Utils/Utils.hpp"

namespace zp
{

class Socket
{
public:
    Socket() = default;
    /**
     * @brief Will call connect to connect to the server
     * @param port
     * @param ip default to localhost
     */
    Socket(const std::string &port, const std::string &ip = "127.0.0.1");
    ~Socket() = default;

    /**
     * @brief Call select(), and set isReadyTo... Those functions must be called right after update()
     */
    void update();

    /**
     * @brief Connect to the server - Will throw a runtime error if something went wrong
     * @param port
     * @param ip Will default to localhost
     */
    void connect(const std::string &port, const std::string &ip = "127.0.0.1");

    /**
     * @brief Disconnect from the server
     */
    void disconnect();

    /**
     * @brief Send a message to the server - Make sure the socket is ready to Write before
     * @param msg string to send
     */
    void send(const std::string &msg);

    /**
     * @brief Receive a message from the server - Make sure the socket is ready to Read before
     * @return Return a vector of vector of string, each vector of string is a command
     */
    std::unique_ptr<std::vector<std::vector<std::string>>> receive();

    /**
     * @brief Check if the socket is ready to read
     * @return false: not ready, true: ready
     */
    bool isReadyToRead() const { return m_isReadyToRead; }

    /**
     * @brief Check if the socket is ready to write
     * @return false: not ready, true: ready
     */
    bool isReadyToWrite() const { return m_isReadyToWrite; }

private:
    int m_socket;
    struct sockaddr_in m_addr;
    fd_set m_readfds;
    fd_set m_writefds;

    std::string m_ip = "127.0.0.1";
    std::string m_port;

    bool m_isReadyToRead = false;
    bool m_isReadyToWrite = false;
};

};
