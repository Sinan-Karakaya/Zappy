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

    parsing_t *do_parsing(char **args);
    int fill_parsing(char **args, parsing_t *parsing);

#endif /* !PARSING_H_ */
