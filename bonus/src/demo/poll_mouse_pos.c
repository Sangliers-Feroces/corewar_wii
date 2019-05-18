/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

void demo_refresh_mouse_pos(void)
{
    /*_demo->mouse.last_pos = _demo->mouse.mouse_pos;
    _demo->mouse.mouse_pos = sfMouse_getPositionRenderWindow(_demo->win.window);*/
}

static void try_tp(demo_t *demo, int *do_tp)
{
    (void)demo;
    (void)do_tp;
    /*if ((ssize_t)demo->mouse.mouse_pos.x < (ssize_t)(demo->win.w / 4)) {
        demo->mouse.mouse_pos.x += demo->win.w / 2;
        demo->mouse.last_pos.x += demo->win.w / 2;
        *do_tp = 1;
    }
    if ((ssize_t)demo->mouse.mouse_pos.x > (ssize_t)(demo->win.w * 3 / 4)) {
        demo->mouse.mouse_pos.x -= demo->win.w / 2;
        demo->mouse.last_pos.x -= demo->win.w / 2;
        *do_tp = 1;
    }
    if ((ssize_t)demo->mouse.mouse_pos.y < (ssize_t)(demo->win.h / 4)) {
        demo->mouse.mouse_pos.y += demo->win.h / 2;
        demo->mouse.last_pos.y += demo->win.h / 2;
        *do_tp = 1;
    }
    if ((ssize_t)demo->mouse.mouse_pos.y > (ssize_t)(demo->win.h * 3 / 4)) {
        demo->mouse.mouse_pos.y -= demo->win.h / 2;
        demo->mouse.last_pos.y -= demo->win.h / 2;
        *do_tp = 1;
    }*/
}

void demo_poll_mouse_pos(demo_t *demo)
{
    int do_tp = 0;

    if (!demo->win.has_focus)
        return;
    demo_refresh_mouse_pos();
    if (_iu.data.is_focus)
        return;
    try_tp(demo, &do_tp);
    /*if (do_tp)
        sfMouse_setPosition((sfVector2i){demo->mouse.mouse_pos.x,
        demo->mouse.mouse_pos.y}, (sfWindow*)demo->win.window);*/
}
