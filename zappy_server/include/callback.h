/*
** EPITECH PROJECT, 2023
** zappy_server
** File description:
** callback
*/

#ifndef CALLBACK_H_
    #define CALLBACK_H_

    #include "zappy_server.h"

    typedef struct callback_info_s {
        size_t tick_start;
        size_t tick_delay;
        size_t tick_end;
        cmd_t *cmd;
        int fd;
        int (*func)(my_zappy_t *zappy, int fd, cmd_t *cmd);
    } callback_info_t;

    typedef struct callback_s callback_t;
    struct callback_s {
        callback_info_t *info;
        callback_t *next;
        callback_t *prev;
    };

    typedef struct callback_list_s {
        callback_t *first;
        callback_t *last;
    } callback_list_t;

    /// @brief execute all the callback at the good time
    /// @param zappy
    /// @return
    int handle_callbacks(my_zappy_t *zappy);

    /// @brief verif the command and use list_add_callback
    /// @param zappy
    /// @param fd
    /// @param cmd
    /// @return
    int add_to_callback(my_zappy_t *zappy, int fd, cmd_t *cmd);

    /// @brief add an function to the callback list
    /// @param callback_list
    /// @param callback_info
    void list_add_callback(callback_list_t *callback_list,
    callback_info_t *callback_info);

    /// @brief destroy the callback list
    /// @param list
    /// @param callback
    /// @return
    size_t destroy_callback(callback_list_t *list, callback_t *callback);

    /// @brief init the callback info struct
    /// @param fd
    /// @param cmd
    /// @param func
    /// @param delay
    /// @return
    callback_info_t *init_callback_info(int fd, cmd_t *cmd,
    int (*func)(my_zappy_t *zappy, int fd, cmd_t *cmd), time_vector_t delay);

#endif /* !CALLBACK_H_ */
