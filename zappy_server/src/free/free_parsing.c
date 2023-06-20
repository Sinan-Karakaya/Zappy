/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** free_parsing
*/

#include "parsing.h"
#include <stdlib.h>
#include <stdio.h>

size_t free_parsing(parsing_t *parsing)
{
    if (!parsing)
        return 84;
    if (parsing->names) {
        for (size_t i = 0; parsing->names[i]; i++) {
            printf("freeing %s\n", parsing->names[i]);
            free(parsing->names[i]);
            printf("freed\n");
        }
        free(parsing->names);
    }
    free(parsing);
    return 0;
}
