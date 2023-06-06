/*
** EPITECH PROJECT, 2023
** project (Workspace) [WSL: Ubuntu-22.04]
** File description:
** Chat
*/

#pragma once

#include <string>
#include <stack>

namespace zp {

class Chat
{
public:
    Chat() = default;
    ~Chat() = default;

    void addMessage(const std::string &name, const std::string &message);
    const std::stack<std::pair<std::string, std::string>> &getMessages() const;

private:
    std::stack<std::pair<std::string, std::string>> m_messages;
};

};
