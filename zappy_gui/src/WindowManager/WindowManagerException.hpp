/*
** EPITECH PROJECT, 2023
** zappy_gui
** File description:
** WindowManagerException
*/

#pragma once

#include <string>
#include <exception>

namespace zp
{

class WindowManagerException : public std::exception
{
public:
    WindowManagerException(std::string const &message) : m_message(message) {};
    ~WindowManagerException() = default;

    const char *what() const noexcept override { return m_message.c_str(); };

private:
    std::string m_message;
};

}
