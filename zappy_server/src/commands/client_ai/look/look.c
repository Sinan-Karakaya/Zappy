/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** look
*/

#include "zappy_server.h"
#include "commands.h"

static int look_right(client_t *client, map_t *map, cmd_t *cmd)
{
    char *result = "[";
    int r_x = 0;
    int r_y = 0;

    for (int i = 0, x = client->info->player->x;
        i <= (int)client->info->player->lvl; i++, x++) {
        for (int y = client->info->player->y - i;
            y <= client->info->player->y + i; y++) {
            r_x = (x < 0) ? (map->x + (x % map->x)) :
            ((x >= map->x) ? (x - map->x) : x);
            r_y = (y < 0) ? (map->y + (y % map->y)) :
            ((y >= map->y) ? (y - map->y) : y);
            asprintf(&result, "%s%s, ", result,
            get_elements_on_tile(map, r_x, r_y));
        }
    } asprintf(&result, "%s]\n", result);
    add_cmd(cmd, result);
    free(result);
    return 0;
}

static int look_left(client_t *client, map_t *map, cmd_t *cmd)
{
    char *result = "[";
    int r_x = 0;
    int r_y = 0;

    for (int i = 0, x = client->info->player->x;
        i <= (int)client->info->player->lvl; i++, x--) {
        for (int y = client->info->player->y + i;
            y >= client->info->player->y - i; y--) {
            r_x = (x < 0) ? (map->x + (x % map->x)) :
            ((x >= map->x) ? (x - map->x) : x);
            r_y = (y < 0) ? (map->y + (y % map->y)) :
            ((y >= map->y) ? (y - map->y) : y);
            asprintf(&result, "%s%s, ", result,
            get_elements_on_tile(map, r_x, r_y));
        }
    } asprintf(&result, "%s]\n", result);
    add_cmd(cmd, result);
    free(result);
    return 0;
}

static int look_up(client_t *client, map_t *map, cmd_t *cmd)
{
    char *result = "[";
    int r_x = 0;
    int r_y = 0;

    for (int i = 0, y = client->info->player->y;
        i <= (int)client->info->player->lvl; i++, y--) {
        for (int x = client->info->player->x - i;
            x <= client->info->player->x + i; x++) {
            r_x = (x < 0) ? (map->x + (x % map->x)) :
            ((x >= map->x) ? (x - map->x) : x);
            r_y = (y < 0) ? (map->y + (y % map->y)) :
            ((y >= map->y) ? (y - map->y) : y);
            asprintf(&result, "%s%s, ", result,
            get_elements_on_tile(map, r_x, r_y));
        }
    } asprintf(&result, "%s]\n", result);
    add_cmd(cmd, result);
    free(result);
    return 0;
}

static int look_down(client_t *client, map_t *map, cmd_t *cmd)
{
    char *result = "[";
    int r_x = 0;
    int r_y = 0;

    for (int i = 0, y = client->info->player->y;
        i <= (int)client->info->player->lvl; i++, y++) {
        for (int x = client->info->player->x + i;
            x >= client->info->player->x - i; x--) {
            r_x = (x < 0) ? (map->x + (x % map->x)) :
            ((x >= map->x) ? (x - map->x) : x);
            r_y = (y < 0) ? (map->y + (y % map->y)) :
            ((y >= map->y) ? (y - map->y) : y);
            asprintf(&result, "%s%s, ", result,
            get_elements_on_tile(map, r_x, r_y));
        }
    } asprintf(&result, "%s]\n", result);
    add_cmd(cmd, result);
    free(result);
    return 0;
}

int look(my_zappy_t *zappy, int fd, cmd_t *cmd)
{
    client_t *client = get_client_by_fd(zappy->client_list, fd);

    if (!client || !zappy || count_args(cmd->args) != 1)
        return add_cmd(cmd, "ko\n");
    if (client->info->player->direction == NORTH)
        look_up(client, zappy->map, cmd);
    if (client->info->player->direction == EAST)
        look_right(client, zappy->map, cmd);
    if (client->info->player->direction == SOUTH)
        look_down(client, zappy->map, cmd);
    if (client->info->player->direction == WEST)
        look_left(client, zappy->map, cmd);
    return 0;
}