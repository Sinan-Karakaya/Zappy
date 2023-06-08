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
    {"pin", &pin}, // OK
    {"sgt", &sgt}, // OK
    {"sst", &sst}, // OK
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

int handle_commands(my_zappy_t *zappy, int client_fd, cmd_t *cmd)
{
    client_t *client = get_client_by_fd(zappy->client_list, client_fd);

    if (!zappy || !cmd || !cmd->args || !client)
        return 0;
    print_debug(client, cmd->args);
    if (client->info->team_id == -1)
        return set_team(zappy, client_fd, cmd);
    if (client->info->player->is_alive == false)
        return 0;
    for (size_t i = 0; commands[i].command != NULL; i++) {
        if (strcmp(commands[i].command, cmd->args[0]) == 0)
            return commands[i].func(zappy, client_fd, cmd);
    }
    send_message(client_fd, "ko\n");
    return 0;
}
