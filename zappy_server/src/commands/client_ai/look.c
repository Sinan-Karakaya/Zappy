/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** look
*/

#include "zappy_server.h"
#include "commands.h"

static char *get_elements_on_tile(map_t *map, size_t x, size_t y)
{
    char *result = "";

    for (my_id_t *i = map->tiles[y][x].players->first; i; i = i->next)
        asprintf(&result, "%splayer ", result);
    if (map->tiles[y][x].is_egg)
        asprintf(&result, "%segg ", result);
    for (size_t i = 0; i < LENGHT_INVENTORY; i++) {
        for (size_t j = 0; j < map->tiles[y][x].inventory[i]; j++)
            asprintf(&result, "%s%s ", result, get_item_name(i));
    }
    return result;
}

static int look_right(client_t *client, map_t *map)
{
    char *result = "[";

    for (int i = 0, x = client->info->player->x;
        i <= (int)client->info->player->lvl; i++, x++) {
        for (int y = client->info->player->y - i;
            y <= client->info->player->y + i; y++) {
            x = (x < 0) ? (map->x - x) : ((x >= map->x) ? (x - map->x) : x);
            y = (y < 0) ? (map->y - y) : ((y >= map->y) ? (y - map->y) : y);
            asprintf(&result, "%s%s, ", result,
            get_elements_on_tile(map, x, y));
        }
    } asprintf(&result, "%s]\n", result);
    send_message(client->info->fd, result), free(result);
    return 0;
}

static int look_left(client_t *client, map_t *map)
{
    char *result = "[";

    for (int i = 0, x = client->info->player->x;
        i <= (int)client->info->player->lvl; i++, x--) {
        for (int y = client->info->player->y - i;
            y <= client->info->player->y + i; y++) {
            x = (x < 0) ? (map->x - x) : ((x >= map->x) ? (x - map->x) : x);
            y = (y < 0) ? (map->y - y) : ((y >= map->y) ? (y - map->y) : y);
            asprintf(&result, "%s%s, ", result,
            get_elements_on_tile(map, x, y));
        }
    } asprintf(&result, "%s]\n", result);
    send_message(client->info->fd, result), free(result);
    return 0;
}

static int look_up(client_t *client, map_t *map)
{
    char *result = "[";

    for (int i = 0, y = client->info->player->y;
        i <= (int)client->info->player->lvl; i++, y--) {
        for (int x = client->info->player->x - i;
            x <= client->info->player->x + i; x++) {
            x = (x < 0) ? (map->x - x) : ((x >= map->x) ? (x - map->x) : x);
            y = (y < 0) ? (map->y - y) : ((y >= map->y) ? (y - map->y) : y);
            asprintf(&result, "%s%s, ", result,
            get_elements_on_tile(map, x, y));
        }
    } asprintf(&result, "%s]\n", result);
    send_message(client->info->fd, result), free(result);
    return 0;
}

static int look_down(client_t *client, map_t *map)
{
    char *result = "[";

    for (int i = 0, y = client->info->player->y;
        i <= (int)client->info->player->lvl; i++, y++) {
        for (int x = client->info->player->x - i;
            x <= client->info->player->x + i; x++) {
            x = (x < 0) ? (map->x - x) : ((x >= map->x) ? (x - map->x) : x);
            y = (y < 0) ? (map->y - y) : ((y >= map->y) ? (y - map->y) : y);
            asprintf(&result, "%s%s, ", result,
            get_elements_on_tile(map, x, y));
        }
    } asprintf(&result, "%s]\n", result);
    send_message(client->info->fd, result), free(result);
    return 0;
}

int look(my_zappy_t *zappy, int fd, char **args)
{
    client_t *client = get_client_by_fd(zappy->client_list, fd);

    if (!client || !zappy || count_args(args) != 1)
        return send_message(fd, "ko\n");
    if (client->info->player->direction == NORTH)
        look_up(client, zappy->map);
    if (client->info->player->direction == EAST)
        look_right(client, zappy->map);
    if (client->info->player->direction == SOUTH)
        look_down(client, zappy->map);
    if (client->info->player->direction == WEST)
        look_left(client, zappy->map);
    return 0;
}
