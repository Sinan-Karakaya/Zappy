/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** bct
*/

#include "zappy_server.h"
#include "commands.h"

int bct(my_zappy_t *zappy, int fd, char **args)
{
    char *result = NULL;
    int x = 0;
    int y = 0;

    if (zappy == NULL || args == NULL)
        return 0;
    if (count_args(args) != 3 || x < 0 || x >= (int)zappy->map->x || y < 0
        || y >= (int)zappy->map->y) {
        send_message(fd, "Bad arguments\n");
        return 0;
    } x = atoi(args[1]);
    y = atoi(args[2]);
    asprintf(&result, "bct %d %d %ld %ld %ld %ld %ld %ld %ld\n", x, y,
        zappy->map->tiles[x][y].food, zappy->map->tiles[x][y].linemate,
        zappy->map->tiles[x][y].deraumere, zappy->map->tiles[x][y].sibur,
        zappy->map->tiles[x][y].mendiane, zappy->map->tiles[x][y].phiras,
        zappy->map->tiles[x][y].thystame);
    send_message(fd, result);
    return 0;
}
