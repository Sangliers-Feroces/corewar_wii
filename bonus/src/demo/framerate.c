/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

void demo_update_framerate(demo_t *demo)
{
    static size_t frame = 0;
    size_t stride = 4;

    if (!_demo->win.has_focus) {
        _demo->win.framelen = 0.000000001;
        return;
    }
    frame++;
    if (frame >= stride) {
        demo->win.framelen =
        /*sfTime_asSeconds(sfClock_getElapsedTime(demo->win.frametime)) /
        (float)stride;
        sfClock_restart(demo->win.frametime);*/
        frame = 0;
        demo->win.fps_to_display = 1.0f / demo->win.framelen;
        /*if (sfKeyboard_isKeyPressed(sfKeyLControl))
            demo->win.framelen *= 0.2;*/
    }
}
