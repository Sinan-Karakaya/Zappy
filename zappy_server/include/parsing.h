/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** parsing
*/

#ifndef PARSING_H_
    #define PARSING_H_

    #include <stddef.h>

    typedef struct parsing_s {
        int port;
        int width;
        int height;
        int clients_nb;
        int freq;
        char **names;
    } parsing_t;


    /// @brief Do the parsing of the arguments
    /// @param args the arguments
    /// @return a parsing_t struct with the arguments
    parsing_t *do_parsing(char **args);

    /// @brief Fill the parsing struct
    /// @param args the arguments
    /// @param parsing  the parsing struct
    /// @return 0 if suceed or 84 if error
    int fill_parsing(char **args, parsing_t *parsing);

#endif /* !PARSING_H_ */
