/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** utils
*/

#ifndef UTILS_H_
    #define UTILS_H_

    #include <stddef.h>
    #include "clients.h"
    #include "map.h"

    typedef struct vector_s {
        int x;
        int y;
    } vector_t;

    typedef struct list_s {
        void *first;
        void *last;
    } list_t;

    typedef struct key_value_s {
        char *key;
        int value;
    } key_value_t;

    // Utils

    /// @brief count the number of args
    /// @param args the args
    /// @return the number of args
    size_t count_args(char **args);

    /// @brief separate a string with a list of separator
    /// @param str the string to separate
    /// @param sep the list of separator
    /// @return the string separated
    char **my_str_to_word_array(char *str, char *sep);


    /// @brief replace the '\r' and the '\n' by \0
    /// @param buffer the buffer to replace
    /// @return 0 if suceed or 84 if error
    int replace_char(char *buffer);


    /// @brief free a char **
    /// @param command the char ** to free
    /// @return NULL
    char **free_command(char **command);

    /// @brief init the list
    /// @return the list
    list_t *init_list(void);

    /// @brief get item name
    /// @param item the item
    /// @return the item name
    const char *get_item_name(size_t item);

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

#endif /* !UTILS_H_ */
