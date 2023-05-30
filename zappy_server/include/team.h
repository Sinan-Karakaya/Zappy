/*
** EPITECH PROJECT, 2023
** B-NWP-400-REN-4-1-myteams-axel.rohee
** File description:
** zappy
*/

#ifndef TEAMS_H_
    #define TEAMS_H_

    #include "my_uuid.h"
    #include <string.h>

    typedef struct team_info_s {
        char *name;
        char *description;
        uuid_t team_uuid;
        uuid_list_t *client_list;
    } team_info_t;

    typedef struct team_s team_t;
    struct team_s {
        team_info_t *info;
        team_t *next;
        team_t *prev;
    };

    typedef struct team_list_s {
        team_t *first;
        team_t *last;
    } team_list_t;

// Adders
void list_add_teams(team_list_t *teams_list, team_info_t *team_info);

// Initializers
team_info_t *init_teams_info(char *name, char *description);

// Getters
team_t *get_team_by_uuid(team_list_t *teams_list, char *team_uuid);
team_t *get_team_by_name(team_list_t *teams_list, char *name);
team_info_t *get_team_info(team_list_t *teams_list, char *team_uuid);
uuid_list_t *get_team_client_list(team_list_t *teams_list, char *team_uuid);

#endif /* !TEAMS_H_ */
