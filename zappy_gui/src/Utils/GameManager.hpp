/*
** EPITECH PROJECT, 2023
** src/Utils
** File description:
** GameManager
*/

#pragma once

#include <string>

namespace zp
{

    class GameManager
    {
    public:
        GameManager() = delete;
        ~GameManager() = delete;

        static void stateGame(const std::string &winnerTeam)
        {
            m_isEndGame = !m_isEndGame;
            m_winnerTeam = winnerTeam;
        }
        static std::pair<bool, std::string> isEndGame() { return {m_isEndGame, m_winnerTeam}; }

    private:
        inline static bool m_isEndGame = false;
        inline static std::string m_winnerTeam;
    };
}
