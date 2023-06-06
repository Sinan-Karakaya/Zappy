/*
** EPITECH PROJECT, 2023
** project (Workspace) [WSL: Ubuntu-22.04]
** File description:
** Chat
*/

#include "Chat.hpp"

void zp::Chat::addMessage(const std::string &name, const std::string &message)
{
    if (m_messages.size() >= 10)
        m_messages.pop();
    m_messages.push(std::make_pair(name, message));
}

const std::stack<std::pair<std::string, std::string>> &zp::Chat::getMessages() const
{
    return m_messages;
}
