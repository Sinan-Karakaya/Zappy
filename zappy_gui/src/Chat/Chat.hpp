/*
** EPITECH PROJECT, 2023
** project (Workspace) [WSL: Ubuntu-22.04]
** File description:
** Chat
*/

#pragma once

#include <string>
#include <deque>

namespace zp {

class Chat
{
public:
    Chat() = default;
    ~Chat() = default;

    /**
     * @brief Add a message to the stack
     * @param name Name of the player that send the message
     * @param message Content of the message
     */
    void addMessage(const std::string &name, const std::string &message);

    /**
     * @brief Get the messages
     * @return Stack of messages
     */
    const std::deque<std::pair<std::string, std::string>> &getMessages() const;

private:
    std::deque<std::pair<std::string, std::string>> m_messages;
};

};
