/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** mct
*/

#include "zappy_server.h"
#include "commands.h"

static char *get_full_map(my_zappy_t *zappy)
{
    char *tmp = calloc(1, sizeof(char));
    char *temp = NULL;

    for (ssize_t i = 0; i < zappy->map->y; i++) {
        for (ssize_t j = 0; j < zappy->map->x; j++) {
            temp = NULL;
            asprintf(&temp, "%sbct %ld %ld %ld %ld %ld %ld %ld %ld %ld\n",
                tmp, i, j, zappy->map->tiles[i][j].inventory[FOOD],
                zappy->map->tiles[i][j].inventory[LINEMATE],
                zappy->map->tiles[i][j].inventory[DERAUMERE],
                zappy->map->tiles[i][j].inventory[SIBUR],
                zappy->map->tiles[i][j].inventory[MENDIANE],
                zappy->map->tiles[i][j].inventory[PHIRAS],
                zappy->map->tiles[i][j].inventory[THYSTAME]);
            free(tmp);
            tmp = temp;
        }
    }
    return tmp;
}

int mct(my_zappy_t *zappy, NUSED int fd, cmd_t *cmd)
{
    char *temp = NULL;

    if (zappy == NULL || cmd->args == NULL)
        return 0;
    if (count_args(cmd->args) != 1) {
        add_cmd(cmd, "ko\n");
        return 0;
    } temp = get_full_map(zappy);
    add_cmd(cmd, temp);
    free(temp);
    return 0;
}
