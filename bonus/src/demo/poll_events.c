/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

/*static int do_stuff_event_ext(demo_t *demo, sfEvent event)
{
    switch (event.type) {
    case sfEvtGainedFocus:
        demo->win.has_focus = 1;
        _demo->mouse.mouse_pos =
        sfMouse_getPositionRenderWindow(_demo->win.window);
        break;
    case sfEvtLostFocus:
        demo->win.has_focus = 0;
        _demo->mouse.last_pos = _demo->mouse.mouse_pos;
        break;
    default:
        break;
    }
    return 1;
}

static int do_stuff_event(demo_t *demo, sfEvent event)
{
    switch (event.type) {
    case sfEvtClosed:
        sfRenderWindow_close(demo->win.window);
        return (0);
    case sfEvtMouseButtonPressed:
        demo->mouse.button_state |= (1 << event.mouseButton.button);
        break;
    case sfEvtMouseButtonReleased:
        demo->mouse.button_state &= ~(1 << event.mouseButton.button);
        break;
    default:
        return do_stuff_event_ext(demo, event);
    }
    return (1);
}

static void poll_click(demo_t *demo)
{
    demo->mouse.button_click = 0;
    for (size_t i = 0; i < 16; i++)
        demo->mouse.button_click |=
        ((((demo->mouse.button_state >> i) & 1) == 1) &&
        (((demo->mouse.button_last >> i) & 1) == 0)) << i;
    demo->mouse.button_release = 0;
    for (size_t i = 0; i < 16; i++)
        demo->mouse.button_release |=
        ((((demo->mouse.button_state >> i) & 1) == 0) &&
        (((demo->mouse.button_last >> i) & 1) == 1)) << i;
}*/

int demo_poll_events(demo_t *demo)
{
    (void)demo;
    /*sfEvent event;

    if (!sfRenderWindow_isOpen(demo->win.window))
        return (0);
    demo->mouse.button_last = demo->mouse.button_state;
    while (sfRenderWindow_pollEvent(demo->win.window, &event))
        if (!do_stuff_event(demo, event))
            return (0);
    demo_poll_mouse_pos(demo);
    poll_click(demo);
    demo_poll_input(demo);
    refresh_sound_volume();*/
    return (1);
}
