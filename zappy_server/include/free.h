/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** free
*/

#ifndef FREE_H_
    #define FREE_H_

    #include "zappy_server.h"

    /// @brief free all the zappy struct
    /// @param zappy the zappy struct
    /// @return 0 if success, 84 if error
    size_t free_zappy(my_zappy_t *zappy);

    /// @brief free all the parsing struct
    /// @param parsing the parsing struct
    /// @return 0 if success, 84 if error
    size_t free_parsing(parsing_t *parsing);

    /// @brief free all the client info struct
    /// @param client
    void destroy_client_info(client_info_t *client);

    /// @brief free the team_list struct
    /// @param team_list
    void free_team_list(team_list_t *team_list);

    /// @brief free the cmd struct
    /// @param cmd
    void destroy_cmd(cmd_t *cmd);

    /// @brief free the client_list struct
    /// @param client_list
    void free_client_list(client_list_t *client_list);

    /// @brief free the egg_list struct
    /// @param egg_list
    void free_egg_list(egg_list_t *egg_list);

    /// @brief free the team struct
    /// @param team
    void destroy_struct_team(team_t *team);

    /// @brief free the map struct
    /// @param map
    void destroy_map(map_t *map);

    /// @brief free the client_info struct
    /// @param info
    void destroy_client_info(client_info_t *info);

#endif /* !FREE_H_ */
