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
    Socket(const std::string &port, const std::string &ip = "127.0.0.1");
    ~Socket() = default;

    void update();
    void connect(const std::string &port, const std::string &ip = "127.0.0.1");
    void disconnect();
    void send(const std::string &msg);
    std::unique_ptr<std::vector<std::vector<std::string>>> receive();

    bool isReadyToRead() const { return m_isReadyToRead; }
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
