/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

void demo_update_cursor_visibility(demo_t *demo)
{
    (void)demo;
    /*sfWindow_setMouseCursorVisible((sfWindow*)demo->win.window,
    _iu.data.is_focus);*/
}

void demo_center_cursor(demo_t *demo)
{
    (void)demo;
    /*sfMouse_setPosition((sfVector2i){demo->win.w / 2, demo->win.h / 2},
    (sfWindow*)demo->win.window);*/
}

static void editor_shortcut(demo_t *demo)
{
    if (demo->input.key_press['N'] && _iu.data.mode_dev)
        demo->world.player->trans.is_physics =
        !demo->world.player->trans.is_physics;
    if (demo->input.key_press[KEY_TAB]) {
        _iu.data.is_invent = !_iu.data.is_invent;
        if (_iu.data.is_invent)
            demo_center_cursor(demo);
        demo_update_cursor_visibility(demo);
        invent_loop();
    }
    if (demo->input.key_press[KEY_ESC])
        pause_loop();
    if (_demo->input.key_press['J'])
        _iu.data.iu_is_display = !_iu.data.iu_is_display;
    if (_demo->input.key_press['B'] && _iu.data.mode_dev)
        world_spawn_boss();
    if (_demo->input.key_press['M'] && _iu.data.mode_dev)
        vg_next_mq();
}

void editor(demo_t *demo)
{
    if (!demo->win.has_focus)
        return;
    editor_shortcut(demo);
}
