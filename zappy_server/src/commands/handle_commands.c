/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** handle_commands
*/

#include "zappy_server.h"
#include "commands.h"

commands_t commands[] = {
    /*
        PROTOCOL GRAPHIC
    */
    {"msz", &msz}, // OK
    {"bct", &bct}, // OK
    {"mct", &mct}, // OK
    {"tna", &tna}, // OK
    {"ppo", &ppo}, // OK
    {"plv", &plv}, // OK
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

static int print_debug(client_t *client, char **cmd)
{
    if (client == NULL || cmd == NULL)
        return 84;
    printf("Client %d: ", client->info->fd);
    for (size_t i = 0; cmd[i] != NULL; i++)
        printf("%s ", cmd[i]);
    printf("\n");
    return 0;
}

int handle_commands(my_zappy_t *zappy, int client_fd, char **cmd)
{
    client_t *client = get_client_by_fd(zappy->client_list, client_fd);

    if (zappy == NULL || cmd == NULL || client == NULL)
        return 0;
    print_debug(client, cmd);
    if (client->info->team_id == -1)
        return set_team(zappy, client_fd, cmd);
    for (size_t i = 0; commands[i].command != NULL; i++) {
        if (strcmp(commands[i].command, cmd[0]) == 0)
            return commands[i].func(zappy, client_fd, cmd);
    }
    send_message(client_fd, "ko\n");
    return 0;
}
