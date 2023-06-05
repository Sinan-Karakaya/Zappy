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
    /*
        PROTOCOL GRAPHIC
    */
    {"msz", &msz}, // OK
    {"bct", &bct}, // OK
    {"mct", &mct}, // OK
    {"tna", &tna}, // OK
    {"ppo", &ppo}, // OK
    {"plv", &plv},
    {"pin", &pin},
    {"sgt", &sgt},
    {"sst", &sst},
    /*
        PROTOCOL AI
    */
    {"Forward", &forward},
    {"Right", &right},
    {"Left", &left},
    {"Look", &look},
    {"Inventory", &inventory},
    {"Broadcast", &broadcast},
    {"Connect_nbr", &connect_nbr},
    {"Fork", &fork_cmd},
    {"Eject", &eject},
    {"Take", &take},
    {"Set", &set},
    {"Incantation", &incantation},
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
