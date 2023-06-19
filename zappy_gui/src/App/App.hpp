/*
** EPITECH PROJECT, 2023
** zappy_gui
** File description:
** App
*/

#pragma once

#include <iostream>
#include <memory>

#include <spdlog/spdlog.h>

#include "WindowManager/WindowManager.hpp"
#include "WindowManager/WindowManagerException.hpp"
#include "NetworkManager/NetworkManager.hpp"
#include "Map/Map.hpp"
#include <Chat/Chat.hpp>

namespace zp
{

class App
{
public:
    App(const std::string &port, const std::string &ip = "127.0.0.1");
    ~App() = default;

    void run();

private:
    std::unique_ptr<WindowManager> m_windowManager;
    std::unique_ptr<NetworkManager> m_networkManager;
    std::unique_ptr<Map> m_map;
    std::unique_ptr<Chat> m_chat;

    bool isConnected = false;
};

} // zp
