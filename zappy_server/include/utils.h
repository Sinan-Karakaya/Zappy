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

    // Utils
    size_t count_args(char **args);
    char **my_str_to_word_array(char *str, char *sep);
    char *uuid_to_char(uuid_t uuid);
    int replace_char(char *buffer);
    char **free_command(char **command);

#endif /* !UTILS_H_ */
