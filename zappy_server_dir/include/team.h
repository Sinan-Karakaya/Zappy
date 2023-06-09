/*
** EPITECH PROJECT, 2023
** B-NWP-400-REN-4-1-myteams-axel.rohee
** File description:
** zappy
*/

#ifndef TEAMS_H_
    #define TEAMS_H_

    #include "my_id.h"
    #include <string.h>
    #include <stdbool.h>

    #define  TEAM_ID_GRAPHIC 0

    typedef struct team_info_s {
        char *name;
        size_t nb_clients;
        int team_id;
        id_list_t *client_list;
        bool printable;
        ssize_t slots_available;
        size_t nb_eggs;
        size_t actual_users;
        size_t max_slots;
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
team_info_t *init_teams_info(char *name, int id);

// Getters

/// @brief get a team info by his id
/// @param teams_list the list of teams
/// @param team_id the id of the team
/// @return the team info
team_t *get_team_by_id(team_list_t *teams_list, int team_id);

/// @brief get a team info by his name
/// @param teams_list the list of teams
/// @param name the name of the team
/// @return the team info
team_t *get_team_by_name(team_list_t *teams_list, char *name);

/// @brief get a team info by his id
/// @param teams_list the list of teams
/// @param team_id the id of the team
/// @return the team info
team_info_t *get_team_info(team_list_t *teams_list, int team_id);

/// @brief get a team client list by his id
/// @param teams_list the list of teams
/// @param team_id the id of the team
/// @return the team client list
id_list_t *get_team_client_list(team_list_t *teams_list, int team_id);

// Deletors

/// @brief destroy a team
/// @param list the list of teams
/// @param team the team to destroy
/// @return 0 if success, 84 if error
size_t destroy_team(team_list_t *list, team_t *team);

#endif /* !TEAMS_H_ */
