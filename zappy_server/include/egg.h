/*
** EPITECH PROJECT, 2023
** zappy_server
** File description:
** egg
*/

#ifndef EGG_H_
    #define EGG_H_

typedef struct egg_s {
    int id;
    int team_id;
    int player_id;
    int x;
    int y;
    struct egg_s *next;
    struct egg_s *prev;
} egg_t;


#endif /* !EGG_H_ */
