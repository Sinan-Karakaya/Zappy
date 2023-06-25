/*
** EPITECH PROJECT, 2023
** zappy_server
** File description:
** tests_messages
*/

#include <criterion/criterion.h>
#include "utils.h"
#include "commands.h"

Test (messages, count_array)
{
    char *msg = "Hello World Test";
    cmd_t *cmd = malloc(sizeof(cmd_t));
    my_zappy_t *zappy = malloc(sizeof(my_zappy_t));
    client_info_t *info = init_clients_info(1, 10, 10);

    zappy->client_list = (client_list_t *)init_list();
    list_add_client(zappy->client_list, info);
    zappy->client_list->first->info->team_id = TEAM_ID_GRAPHIC;

    cmd->result = my_str_to_word_array(msg, " ");

    send_message(1, msg);
    send_message_lb(1, msg);
    send_message_error(1, msg);
    send_all_message(cmd, 1);
    send_to_graphics(zappy, msg);
    destroy_client_in_list(zappy->client_list, 1);
    free(cmd->result);
    free(cmd);
    free(zappy);
}
