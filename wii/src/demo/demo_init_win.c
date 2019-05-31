/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

static int init_mouse(demo_t *demo)
{
    (void)demo;
    /*demo->mouse.button_state = 0;
    demo->mouse.button_release = 0;
    demo->mouse.button_click = 0;
    for (size_t i = 0; i < 2; i++)
        demo_refresh_mouse_pos();
    demo_update_cursor_visibility(demo);
    for (size_t i = 0; i < 256; i++) {
        demo->input.key_state[i] = 0;
        demo->input.key_last[i] = 0;
        demo->input.key_press[i] = 0;
    }*/
    return (1);
}

static void create_win(demo_t *demo)
{
    (void)demo;
    /*sfUint32 style = sfClose;

    if (settings_load().screen_state == FULLSCREEN)
        style |= sfFullscreen;
    demo->win.w = 1920;
    demo->win.h = 1080;
    demo->win.window = sfRenderWindow_create((sfVideoMode){demo->win.w,
    demo->win.h, 32}, "rtx on !", style,
    &(sfContextSettings){24, 8, 2, 4, 3, 0, 1});
    if (demo->win.window == NULL)
        exit_full_custom();
    refresh_win_size();*/
}

void demo_init_win(demo_t *demo)
{
    create_win(demo);
    /*demo->win.frametime = sfClock_create();
    if (demo->win.frametime == NULL)
        exit(1);*/
    demo->win.framelen = 1.0f / 60.0f;
    demo->win.fps_to_display = 60;
    demo->win.has_focus = 1;
    demo->win.do_reboot = 0;
    //sfWindow_setVerticalSyncEnabled((sfWindow*)demo->win.window, sfTrue);
    if (!init_mouse(demo))
        exit(1);
}
