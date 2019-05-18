/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** demo_time
*/

#include "headers.h"

double clocks_get_eleapsed_time_second(void)
{
    return 1.0 / 60.0;
    /*sfTime result = sfClock_getElapsedTime(_demo->clocks.game_clock);

    return (result.microseconds / 1000000.0);*/
}

void clocks_refresh_time(void)
{
    _demo->clocks.t += _demo->win.framelen;
}

void clocks_init(demo_t *demo)
{
    (void)demo;
    //demo->clocks.game_clock = sfClock_create();
    demo->clocks.t = 0.0;
}

void clocks_quit(demo_t *demo)
{
    (void)demo;
    //sfClock_destroy(demo->clocks.game_clock);
}
