/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** parsing
*/

#include "parsing.h"
#include <stdlib.h>
#include <string.h>

static parsing_t *init_parsing(void)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));

    if (!parsing)
        return NULL;
    parsing->port = 4242;
    parsing->width = 10;
    parsing->height = 10;
    parsing->names = malloc(sizeof(char *) * 5);
    if (!parsing->names)
        return NULL;
    parsing->names[0] = strdup("Team1");
    parsing->names[1] = strdup("Team2");
    parsing->names[2] = strdup("Team3");
    parsing->names[3] = strdup("Team4");
    parsing->names[4] = NULL;
    parsing->clients_nb = 3;
    parsing->freq = 100;
    return parsing;
}

static int check_parsing(parsing_t *parsing)
{
    if (!parsing)
        return 84;
    if (parsing->port == 0 || parsing->width < 10 || parsing->width > 30
    || parsing->height < 10 || parsing->height > 30
    || parsing->names == NULL || parsing->clients_nb == 0
    || parsing->freq < 2 || parsing->freq > 10000)
        return 84;
    return 0;
}

parsing_t *do_parsing(char **args)
{
    parsing_t *parsing = init_parsing();

    if (!parsing)
        return NULL;
    if (fill_parsing(args, parsing) == 84)
        return NULL;
    if (check_parsing(parsing) == 84)
        return NULL;
    return parsing;
}
