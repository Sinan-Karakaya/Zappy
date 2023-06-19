/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** seg
*/

#include "free.h"
#include "commands.h"

int seg(my_zappy_t *zappy, char *team_name)
{
    char *result = NULL;
    team_t *team = NULL;

    if (zappy == NULL)
        return 0;
    team = get_team_by_name(zappy->team_list, team_name);
    asprintf(&result, "seg %s\n", team->info->name);
    send_to_graphics(zappy, result);
    free(result);
    zappy->is_end = true;
    return 0;
}
