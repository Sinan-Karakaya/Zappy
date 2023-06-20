/*
** EPITECH PROJECT, 2023
** B-NWP-400-REN-4-1-myteams-thomas.juin
** File description:
** rework str to word array
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

static size_t count_separators(char *str, char *separators)
{
    size_t count = 0;

    if (!str || !separators)
        return (0);
    for (size_t i = 0; str[i] != '\0'; i++) {
        for (size_t y = 0; separators[y] != '\0'; y++) {
            count += (str[i] == separators[y]) ? 1 : 0;
        }
    }
    return (count);
}

static bool check_separators(char c, char *separators)
{
    size_t iterator = 0;

    if (!separators)
        return (false);
    for (size_t y = 0; separators[y] != '\0'; y++)
        if (c == separators[y])
            iterator++;
    if (iterator == 0)
        return (true);
    return (false);
}

static size_t word_size(char *str, int i, char *separators)
{
    size_t count = 0;

    while (check_separators(str[i], separators) && str[i] != '\0') {
        count++;
        i++;
    }
    return (count);
}

static size_t replace_character(char *str, char *separators, char *result,
size_t i)
{
    size_t k = 0;

    for (k = 0; str[i] != '\0'; k++, i++) {
        if (check_separators(str[i], separators)) {
            result[k] = str[i];
            result[k + 1] = '\0';
        } else
            break;
    }
    return (i);
}

char **my_str_to_word_array(char *str, char *separators)
{
    char **result = calloc((count_separators(str, separators) + 2),
    sizeof(char *));
    size_t j = 0;

    if (!result || !str || !separators)
        return NULL;
    for (size_t i = 0; str[i]; i++) {
        while (check_separators(str[i], separators) == 0 && str[i] != '\0')
            i++;
        result[j] = calloc((word_size(str, i, separators) + 2), sizeof(char));
        if (!result[j])
            return NULL;
        i = replace_character(str, separators, result[j], i);
        j++;
        if (i >= strlen(str))
            break;
    }
    return result;
}
