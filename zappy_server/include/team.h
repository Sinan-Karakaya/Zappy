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
        size_t nb_clients;
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

/// @brief add a team to the list
/// @param teams_list the list of teams
/// @param team_info the info of the team
void list_add_teams(team_list_t *teams_list, team_info_t *team_info);

// Initializers

/// @brief init a team info
/// @param name the name of the team
/// @return the team info
team_info_t *init_teams_info(char *name);

// Getters

/// @brief get a team info by his uuid
/// @param teams_list the list of teams
/// @param team_uuid the uuid of the team
/// @return the team info
team_t *get_team_by_uuid(team_list_t *teams_list, char *team_uuid);

/// @brief get a team info by his name
/// @param teams_list the list of teams
/// @param name the name of the team
/// @return the team info
team_t *get_team_by_name(team_list_t *teams_list, char *name);

/// @brief get a team info by his uuid
/// @param teams_list the list of teams
/// @param team_uuid the uuid of the team
/// @return the team info
team_info_t *get_team_info(team_list_t *teams_list, char *team_uuid);

/// @brief get a team client list by his uuid
/// @param teams_list the list of teams
/// @param team_uuid the uuid of the team
/// @return the team client list
uuid_list_t *get_team_client_list(team_list_t *teams_list, char *team_uuid);

#endif /* !TEAMS_H_ */
