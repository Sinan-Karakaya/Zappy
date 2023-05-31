/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** fill_parsing
*/

#include "parsing.h"
#include "utils.h"
#include <stdlib.h>
#include <string.h>

static char **add_to_names(char **names, char *new_name)
{
    size_t size = 0;
    char **result = NULL;

    if (!names || !new_name)
        return NULL;
    size = count_args(names);
    result = malloc(sizeof(char *) * (size + 2));
    if (!result)
        return NULL;
    for (int i = 0; names[i]; i++) {
        result[i] = names[i];
    }
    result[size] = new_name;
    result[size + 1] = NULL;
    return result;
}

static int name_flag(char **args, parsing_t *parsing, int i)
{
    if (!args || !parsing)
        return 84;
    if (parsing->names) {
        for (int i = 0; parsing->names[i]; i++)
            free(parsing->names[i]);
        free(parsing->names);
        parsing->names = malloc(sizeof(char *) * 1);
        if (!parsing->names)
            return 84;
        parsing->names[0] = NULL;
    }
    while (args[i + 1] != NULL && args[i + 1][0] != '-') {
        parsing->names = add_to_names(parsing->names, args[i + 1]);
        i++;
    }
    return 0;
}

int fill_parsing(char **args, parsing_t *parsing)
{
    if (!parsing || !args)
        return 84;
    for (int i = 1; args[i]; i++) {
        if (strcmp(args[i], "-p") == 0)
            parsing->port = atoi(args[i + 1]);
        if (strcmp(args[i], "-x") == 0)
            parsing->width = atoi(args[i + 1]);
        if (strcmp(args[i], "-y") == 0)
            parsing->height = atoi(args[i + 1]);
        if (strcmp(args[i], "-n") == 0)
            name_flag(args, parsing, i);
        if (strcmp(args[i], "-c") == 0)
            parsing->clients_nb = atoi(args[i + 1]);
        if (strcmp(args[i], "-f") == 0)
            parsing->freq = atoi(args[i + 1]);
    }
    return 0;
}
