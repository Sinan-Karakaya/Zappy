/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** mct
*/

#include "zappy_server.h"
#include "commands.h"

static char **get_full_map(my_zappy_t *zappy)
{
    char **temp = calloc(zappy->map->x, sizeof(char *));
    char *tmp = NULL;

    for (ssize_t i = 0; i < zappy->map->x; i++) {
        temp[i] = calloc(zappy->map->y, sizeof(char));
        for (ssize_t j = 0; j < zappy->map->y; j++) {
            asprintf(&tmp, "bct %ld %ld %ld %ld %ld %ld %ld %ld %ld\n",
                i, j, zappy->map->tiles[i][j].food,
                zappy->map->tiles[i][j].linemate,
                zappy->map->tiles[i][j].deraumere,
                zappy->map->tiles[i][j].sibur,
                zappy->map->tiles[i][j].mendiane,
                zappy->map->tiles[i][j].phiras,
                zappy->map->tiles[i][j].thystame);
            temp[i] = strdup(tmp);
        }
    }
    return temp;
}

int mct(my_zappy_t *zappy, int fd, char **args)
{
    char **temp = NULL;
    char *result = calloc(1, sizeof(char));

    if (zappy == NULL || args == NULL)
        return 0;
    if (count_args(args) != 1) {
        send_message(fd, "ko\n");
        return 0;
    } temp = get_full_map(zappy);
    for (ssize_t i = 0; i < zappy->map->x; i++) {
        for (ssize_t j = 0; j < zappy->map->y; j++) {
            result = realloc(result, strlen(result) + strlen(temp[i]) + 1);
            result = strcat(result, temp[i]);
        }
    }
    send_message(fd, result);
    return 0;
}
