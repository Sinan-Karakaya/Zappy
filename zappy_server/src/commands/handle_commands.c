/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** handle_commands
*/

#include "free.h"
#include "zappy_server.h"
#include "commands.h"
#include "utils.h"

commands_t commands_ai[] = {
    {"Forward", &verify_forward},
    {"Right", &verify_right},
    {"Left", &verify_left},
    {"Look", &verify_look},
    {"Inventory", &verify_inventory},
    {"Broadcast", &verify_broadcast},
    {"Connect_nbr", &verify_connect_nbr},
    {"Fork", &verify_fork},
    {"Eject", &verify_eject},
    {"Take", &verify_take},
    {"Set", &verify_set},
    {"Incantation", &verify_incantation},
    {NULL, NULL}
};

commands_t commands_graphic[] = {
    {"msz", &msz}, // OK
    {"bct", &bct}, // OK
    {"mct", &mct}, // OK
    {"tna", &tna}, // OK
    {"ppo", &ppo}, // OK
    {"plv", &plv}, // OK
    {"pin", &pin}, // OK
    {"sgt", &sgt}, // OK
    {"sst", &sst}, // OK
    {NULL, NULL}
};

static int add_command_list(client_t *client, cmd_t *cmd)
{
    command_t *tmp = NULL;

    if (client == NULL || cmd == NULL)
        return 84;
    if (client->info->lst_cmd->first == NULL) {
        tmp = init_lst_commands(cmd->args);
        list_add_command(client->info->lst_cmd, tmp);
        client->info->lst_cmd->size++;
        return 0;
    } if (client->info->player->is_action == true) {
        if (client->info->lst_cmd->size == 9)
            return 0;
        tmp = init_lst_commands(cmd->args);
        list_add_command(client->info->lst_cmd, tmp);
        client->info->lst_cmd->size++;
    }
    return 0;
}

static bool get_command_list(client_t *client, cmd_t *cmd)
{
    if (client == NULL || cmd == NULL)
        return false;
    if (client->info->player->is_action == false) {
        if (client->info->lst_cmd->first != NULL) {
            pop_front_cmd(client->info->lst_cmd);
            client->info->lst_cmd->size--;
            return true;
        }
    }
    return false;
}

int exec_command(client_t *client, cmd_t *cmd, my_zappy_t *zappy, int client_fd)
{
    if (client->info->player->is_alive == false)
        return 0;
    if (client->info->team_id == TEAM_ID_GRAPHIC)
        return 0;
    if (client->info->lst_cmd->first != NULL &&
        client->info->player->is_action == false &&
        client->info->player->is_incanting == false)
        cmd = init_cmd(client->info->lst_cmd->first->args);
    if (get_command_list(client, cmd) == false)
        return 0;
    for (size_t i = 0; commands_ai[i].command != NULL; i++) {
        if (strcmp(commands_ai[i].command, cmd->args[0]) == 0) {
            client->info->player->is_action = true;
            commands_ai[i].func(zappy, client_fd, cmd);
            return 0;
        }
    }
    return 1;
}

static int exec_graphic_command(client_t *client, cmd_t *cmd,
    my_zappy_t *zappy, int client_fd)
{
    if (client->info->player->is_alive == false)
        return 0;
    for (size_t i = 0; commands_graphic[i].command != NULL; i++) {
        if (strcmp(commands_graphic[i].command, cmd->args[0]) == 0) {
            client->info->player->is_action = true;
            commands_graphic[i].func(zappy, client_fd, cmd);
            return 0;
        }
    }
    return 0;
}

int handle_commands(my_zappy_t *zappy, int client_fd, cmd_t *cmd)
{
    client_t *client = get_client_by_fd(zappy->client_list, client_fd);

    if (!zappy || !cmd || !cmd->args || !client)
        return 0;
    if (cmd && cmd->args)
        print_debug(zappy, client, cmd->args);
    if (client->info->team_id == TEAM_ID_GRAPHIC)
        return exec_graphic_command(client, cmd, zappy, client_fd);
    if (client->info->team_id == -1)
        return set_team(zappy, client_fd, cmd);
    add_command_list(client, cmd);
    return 0;
}
