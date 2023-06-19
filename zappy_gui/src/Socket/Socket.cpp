/*
** EPITECH PROJECT, 2023
** project (Workspace) [WSL: Ubuntu-22.04]
** File description:
** Socket
*/

#include "Socket.hpp"

zp::Socket::Socket(const std::string &port, const std::string &ip)
    : m_ip(ip), m_port(port)
{
    try {
        connect(port, ip);
    } catch (const std::runtime_error &e) {
        spdlog::error(e.what());
    }
}

void zp::Socket::connect(const std::string &port, const std::string &ip)
{
    m_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (m_socket == -1)
        throw std::runtime_error("Error: socket creation failed");
    m_addr.sin_family = AF_INET;
    m_addr.sin_port = htons(std::stoi(port));
    m_addr.sin_addr.s_addr = inet_addr(ip.c_str());
    if (::connect(m_socket, (struct sockaddr *)&m_addr, sizeof(m_addr)) < 0)
        throw std::runtime_error("Error: connection failed");
}

void zp::Socket::disconnect()
{
    close(m_socket);
}

void zp::Socket::send(const std::string &msg)
{
    ::send(m_socket, msg.c_str(), msg.size(), 0);
}

std::unique_ptr<std::vector<std::vector<std::string>>> zp::Socket::receive()
{
    std::string response;
    std::string temp;

    char buffer[1025] = {0};
    int valread;

    while ((valread = read(m_socket, buffer, 1024)) > 0) {
        temp = std::string(buffer);
        response += temp;
        memset(buffer, 0, sizeof(buffer)); // Clear the buffer

        // Break the loop if the received data does not fill the buffer
        if (valread < 1024)
            break;
    }

    if (valread == 0)
        throw std::runtime_error("Error: connection closed");

    return zp::Utils::bigSplit(response, ' ');
}

void zp::Socket::update()
{
    FD_ZERO(&m_readfds);
    FD_SET(m_socket, &m_readfds);
    FD_ZERO(&m_writefds);
    FD_SET(m_socket, &m_writefds);
    if (select(m_socket + 1, &m_readfds, &m_writefds, nullptr, nullptr) < 0)
        throw std::runtime_error("Error: select failed");
    if (FD_ISSET(m_socket, &m_readfds))
        m_isReadyToRead = true;
    else
        m_isReadyToRead = false;

    if (FD_ISSET(m_socket, &m_writefds))
        m_isReadyToWrite = true;
    else
        m_isReadyToWrite = false;
}
