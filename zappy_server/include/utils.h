/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** utils
*/

#ifndef UTILS_H_
    #define UTILS_H_

    #include <stddef.h>
    #include <uuid/uuid.h>

    typedef struct vector_s {
        int x;
        int y;
    } vector_t;

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

#endif /* !UTILS_H_ */
