/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** bct
*/

#include "zappy_server.h"
#include "commands.h"

int bct(my_zappy_t *zappy, int fd, cmd_t *cmd)
{
    char *result = NULL;
    int x = 0, y = 0;

    if (zappy == NULL || cmd->args == NULL)
        return 0;
    if (count_args(cmd->args) != 3) {
        return send_message(fd, "ko\n");
    } x = atoi(cmd->args[1]);
    y = atoi(cmd->args[2]);
    if (x <= 0 || x >= (int)zappy->map->x || y <= 0 || y >= (int)zappy->map->y)
        return send_message(fd, "ko\n");
    asprintf(&result, "bct %d %d %ld %ld %ld %ld %ld %ld %ld\n", x, y,
    zappy->map->tiles[x][y].inventory[FOOD],
    zappy->map->tiles[x][y].inventory[LINEMATE],
    zappy->map->tiles[x][y].inventory[DERAUMERE],
    zappy->map->tiles[x][y].inventory[SIBUR],
    zappy->map->tiles[x][y].inventory[MENDIANE],
    zappy->map->tiles[x][y].inventory[PHIRAS],
    zappy->map->tiles[x][y].inventory[THYSTAME]);
    add_cmd(cmd, result);
    free(result);
    return 0;
}
