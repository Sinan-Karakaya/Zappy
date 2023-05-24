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

namespace zp
{

class App
{
public:
    App();
    ~App() = default;

    void run();

private:
    std::unique_ptr<WindowManager> m_windowManager;
};

} // zp
