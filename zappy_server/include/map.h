/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** map
*/

#ifndef MAP_H_
    #define MAP_H_

    #include "clients.h"
    #include "utils.h"

    #define LENGTH_DENSITY 7

    #define FOOD_DENSITY 0.5
    #define LINEMATE_DENSITY 0.3
    #define DERAUMERE_DENSITY 0.15
    #define SIBUR_DENSITY 0.1
    #define MENDIANE_DENSITY 0.1
    #define PHIRAS_DENSITY 0.08
    #define THYSTAME_DENSITY 0.05

typedef struct {
    size_t inventory[LENGHT_INVENTORY];
    id_list_t *players;
    bool is_egg;
} tiles_t;

    typedef struct {
        ssize_t x;
        ssize_t y;
        tiles_t **tiles;
        size_t *density[LENGTH_DENSITY];
    } map_t;

    typedef struct vector_s {
        int x;
        int y;
    } vector_t;

    map_t *init_map(size_t x, size_t y);

    /// @brief get coordinates
    /// @param client the client
    /// @param map the map
    /// @return the coordinates
    vector_t real_coordinates(client_t *client, map_t *map);

    /// @brief get the elements on a tile
    /// @param map the map
    /// @param x the x
    /// @param y the y
    /// @return the elements on the tile
    char *get_elements_on_tile(map_t *map, size_t x, size_t y);

    void refill_map(map_t *map);

#endif /* !MAP_H_ */
