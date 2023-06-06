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

#endif /* !FREE_H_ */
