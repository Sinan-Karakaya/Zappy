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

    /// @brief free the team struct
    /// @param team
    void destroy_struct_team(team_t *team);

    void destroy_cmd(cmd_t *cmd);

#endif /* !FREE_H_ */
