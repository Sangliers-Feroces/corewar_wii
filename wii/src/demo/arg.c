/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** demo_arg
*/

#include "headers.h"

arg_t get_data_from_arg(int ac, char **av)
{
    arg_t args = {32.0f, 8, 0.28f};

    if (ac != 4) {
        my_fd_putstr(
        "Missing argument values set by default (32, 8, 0.28).\n", 2);
        return args;
    }
    for (int i = 1; i < ac; i++)
        if (!my_char_isnum(av[i])) {
            my_fd_putstr(av[i], 2);
            my_fd_putstr(
            " : Invalid argument values set by default (32, 8, 0.28).\n", 2);
            return args;
        }
    args.size = atof(av[1]);
    args.iter = atof(av[2]);
    args.strenght = atof(av[3]);
    return args;
}
