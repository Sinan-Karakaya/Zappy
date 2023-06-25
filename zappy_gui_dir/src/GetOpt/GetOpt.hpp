/*
** EPITECH PROJECT, 2023
** src/GetOpt
** File description:
** GetOpt
*/

#pragma once

#include <unistd.h>
#include <string>
#include <iostream>

namespace zp
{

class GetOpt
{
public:
    GetOpt() = delete;
    ~GetOpt() = delete;

    static int parseOpt(int ac, char **av, std::string &ip, std::string &port);
    static void printHelp();
};

} // zp
