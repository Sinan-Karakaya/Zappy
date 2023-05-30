/*
** EPITECH PROJECT, 2023
** B-NWP-400-REN-4-1-myteams-axel.rohee
** File description:
** get_command
*/

#include "utils.h"
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int replace_char(char *str)
{
    if (!str)
        return 84;
    for (size_t pos = 0; str[pos]; pos++)
        if (str[pos] == '\r' || str[pos] == '\n')
            str[pos] = '\0';
    return 0;
}

static char *remove_spaces(char *buffer)
{
    char *new_buffer = NULL;
    size_t size = 0;

    if (!buffer)
        return NULL;
    for (; buffer[size]; size++) {
        if (buffer[size] != ' ' && buffer[size] != '\t')
            break;
    }
    new_buffer = strdup(&buffer[size]);
    return new_buffer;
}

static char **add_to_command(char **command, char *buffer)
{
    char **new_command = NULL;
    size_t size = 0;

    if (!command)
        return NULL;
    if (strlen(buffer) == 0)
        return command;
    for (; command[size]; size++);
    new_command = malloc(sizeof(char *) * (size + 2));
    if (!new_command)
        return NULL;
    for (size_t i = 0; command[i]; i++) {
        new_command[i] = command[i];
    }
    new_command[size] = strdup(buffer);
    new_command[size + 1] = NULL;
    return new_command;
}

char **get_command(char *buffer)
{
    char **commands = NULL;
    char **full_command = NULL;

    if (!buffer)
        return NULL;
    replace_char(buffer);
    commands = my_str_to_word_array(buffer, "\"");
    for (size_t i = 0; commands[i]; i++)
        commands[i] = remove_spaces(commands[i]);
    if (!commands || !commands[0])
        return NULL;
    full_command = my_str_to_word_array(commands[0], " \t");
    for (size_t i = 1; commands[i]; i++) {
        if (strlen(commands[i]) > 0)
            full_command = add_to_command(full_command, commands[i]);
    }
    for (size_t i = 0; commands[i]; i++)
        free(commands[i]);
    free(commands);
    return full_command;
}
