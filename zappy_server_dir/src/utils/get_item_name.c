/*
** EPITECH PROJECT, 2023
** zappy_server
** File description:
** get_item_name
*/

#include "stdlib.h"

const char *get_item_name(size_t item)
{
    switch (item) {
        case 0:
            return "food";
        case 1:
            return "linemate";
        case 2:
            return "deraumere";
        case 3:
            return "sibur";
        case 4:
            return "mendiane";
        case 5:
            return "phiras";
        case 6:
            return "thystame";
        default:
            return "";
    }
}
