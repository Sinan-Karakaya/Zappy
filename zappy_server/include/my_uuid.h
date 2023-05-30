/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** my_uuid
*/

#ifndef MY_UUID_H_
    #define MY_UUID_H_

    #include <uuid/uuid.h>
    #include <unistd.h>

typedef struct my_uuid_s my_uuid_t;
struct my_uuid_s {
    uuid_t uuid;
    my_uuid_t *next;
    my_uuid_t *prev;
};

typedef struct uuid_list_s {
    my_uuid_t *first;
    my_uuid_t *last;
} uuid_list_t;

#endif /* !MY_UUID_H_ */
