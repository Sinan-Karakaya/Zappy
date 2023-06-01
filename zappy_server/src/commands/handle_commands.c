/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** handle_commands
*/

#include "zappy_server.h"
#include "commands.h"

commands_t commands[] = {
    {"test", &test},
    {"msz", &msz}, // OK
    {"bct", &bct}, // OK
    {"mct", &mct},
    {"tna", &tna},
    {"ppo", &ppo},
    {"plv", &plv},
    {"pin", &pin},
    {"sgt", &sgt},
    {"sst", &sst},
    {NULL, NULL}
};

int handle_commands(my_zappy_t *zappy, int client_fd, char **cmd)
{
    if (zappy == NULL || cmd == NULL)
        return 0;
    for (size_t i = 0; commands[i].command != NULL; i++) {
        if (strcmp(commands[i].command, cmd[0]) == 0)
            return commands[i].func(zappy, client_fd, cmd);
    }
    send_message(client_fd, "ko\n");
    return 0;
}
