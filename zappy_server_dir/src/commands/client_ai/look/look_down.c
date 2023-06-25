/*
** EPITECH PROJECT, 2023
** zappy_server
** File description:
** look_down
*/

#include "zappy_server.h"
#include "commands.h"
#include "utils.h"

static char *look_down_bis(client_t *client, vector_t vector, map_t *map,
char *result)
{
    int r_x = 0;
    int r_y = 0;
    int y = vector.x;
    int i = vector.y;

    for (int x = client->info->player->x + i;
        x >= client->info->player->x - i; x--) {
        r_x = (x < 0) ? (map->x + (x % map->x)) :
        ((x >= map->x) ? (x - map->x) : x);
        r_y = (y < 0) ? (map->y + (y % map->y)) :
        ((y >= map->y) ? (y - map->y) : y);
        asprintf(&result, "%s%s", result,
        get_elements_on_tile(map, r_x, r_y));
        if (i == (int)client->info->player->lvl
        && x == client->info->player->x - i)
            continue;
        else
            asprintf(&result, "%s, ", result);
    }
    return result;
}

int look_down(client_t *client, map_t *map, cmd_t *cmd)
{
    char *result = "[";

    for (int i = 0, y = client->info->player->y;
        i <= (int)client->info->player->lvl; i++, y++) {
        result = look_down_bis(client, (vector_t){y, i}, map, result);
    } asprintf(&result, "%s]\n", result);
    add_cmd(cmd, result);
    free(result);
    return 0;
}
