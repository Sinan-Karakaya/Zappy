/*
** EPITECH PROJECT, 2023
** zappy_server
** File description:
** tests_arrays
*/

#include <criterion/criterion.h>
#include "utils.h"

Test (array, count_array)
{
    char *test[] = {"Hello", "World", "Test", NULL};

    cr_assert(count_args(test) == 3);
}

Test (array, dup_array)
{
    char *test[] = {"Hello", "World", "Test", NULL};
    char **result = dup_array(test);

    for (int i = 0; test[i] != NULL; i++) {
        cr_assert(strcmp(test[i], result[i]) == 0);
        free(result[i]);
    }
    free(result);
}
