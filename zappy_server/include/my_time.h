/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** time
*/

#ifndef TIME_H_
    #define TIME_H_

    #include <time.h>

    typedef struct my_time_s {
        double actual;
        double last;
        double elapsed;
        size_t time_per_tick;
        size_t nb_ticks;
        time_t *time;
    } my_time_t;

    void refresh_time_per_tick(my_time_t *init_time);
    my_time_t *init_time(size_t frequency);

#endif /* !TIME_H_ */
