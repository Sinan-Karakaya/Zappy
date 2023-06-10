/*
** EPITECH PROJECT, 2023
** zappy_server
** File description:
** egg
*/

#ifndef EGG_H_
    #define EGG_H_

    #include "stddef.h"

    typedef struct egg_info_s {
        size_t id;
        size_t team_id;
        size_t player_id;
        size_t x;
        size_t y;
    } egg_info_t;

    typedef struct egg_s {
        egg_info_t *info;
        struct egg_s *next;
        struct egg_s *prev;
    } egg_t;

    typedef struct egg_list_s {
        egg_t *first;
        egg_t *last;
    } egg_list_t;



/// @brief destroy egg in the list
/// @param list the list of eggs
/// @param egg the egg to destroy
/// @return 0 if success, 84 if error
size_t destroy_egg(egg_list_t *list, egg_t *egg);

/// @brief add egg at the back of the list
/// @param egg_list the list of eggs
/// @param egg_info the egg to add
void list_add_eggs(egg_list_t *egg_list, egg_info_t *egg_info);

/// @brief init egg info
/// @param team_id the team id
/// @param player_id the player id
/// @param x the x position
/// @param y the y position
/// @return the egg info
egg_info_t *init_eggs_info(size_t team_id, size_t player_id, size_t x,
size_t y);

#endif /* !EGG_H_ */
