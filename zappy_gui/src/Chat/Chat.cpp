/*
** EPITECH PROJECT, 2023
** project (Workspace) [WSL: Ubuntu-22.04]
** File description:
** Chat
*/

#include "Chat.hpp"

void zp::Chat::addMessage(const std::string &name, const std::string &message)
{
    if (m_messages.size() >= 50)
        m_messages.pop_back();
    m_messages.push_front(std::make_pair(name, message));
}

const std::deque<std::pair<std::string, std::string>> &zp::Chat::getMessages() const
{
    return m_messages;
}
