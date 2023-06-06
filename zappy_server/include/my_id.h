/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** my_id
*/

#ifndef MY_id_H_
    #define MY_id_H_

    #include <unistd.h>

typedef struct id_s my_id_t;
struct id_s {
    int id;
    my_id_t *next;
    my_id_t *prev;
};

typedef struct id_list_s {
    my_id_t *first;
    my_id_t *last;
} id_list_t;

#endif /* !MY_id_H_ */
