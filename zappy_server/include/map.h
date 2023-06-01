/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** map
*/

#ifndef MAP_H_
    #define MAP_H_

    #include "clients.h"

    #define LENGTH_DENSITY 7

typedef struct {
    size_t x;
    size_t y;
    size_t *density[LENGTH_DENSITY];
} map_t;

map_t *init_map(size_t x, size_t y);

#endif /* !MAP_H_ */
