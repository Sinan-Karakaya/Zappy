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

    #define SERVER_RED "\033[0;31m[SERVER]\033[0m"
    #define SERVER_GREEN "\033[0;32m[SERVER]\033[0m"
    #define SERVER_YELLOW "\033[0;33m[SERVER]\033[0m"
    #define SERVER_BLUE "\033[0;34m[SERVER]\033[0m"
    #define SERVER_MAGENTA "\033[0;35m[SERVER]\033[0m"

    enum DIRECTION {
        SAME,
        N,
        NW,
        W,
        SW,
        S,
        SE,
        E,
        NE
    };

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

    /// @brief duplicate a char **
    /// @param array the array to duplicate
    /// @return the duplicated array
    char **dup_array(char **array);

    /// @brief get the direction of a client
    /// @param client the client
    /// @param other the other client
    /// @return the direction
    size_t get_direction(client_t *client, client_t *other);

    /// @brief get the direction based on the orientation of a client
    /// @param client the client
    /// @param other the other client
    /// @return the direction
    size_t get_real_direction(size_t orientation, size_t direction);

#endif /* !UTILS_H_ */
