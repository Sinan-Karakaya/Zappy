/*
** EPITECH PROJECT, 2023
** zappy_server
** File description:
** tests_parsing
*/


#include <criterion/criterion.h>
#include "zappy_server.h"
#include "utils.h"
#include "commands.h"

Test (Parsing, all)
{
    char *args[] = {"-f", "10", "-p", "10", "-n", "Team1", "-c", "1",
    "-x", "10", "-y", "10", NULL};
    parsing_t *parsing = do_parsing(args);
    init_zappy(parsing);
}
