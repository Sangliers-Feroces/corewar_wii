/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** pause_event
*/

#include "headers.h"

int iu_pause_poll_event(void)
{
    if (!demo_poll_events(_demo))
        return 0;
    if (_demo->input.key_press[KEY_ESC]) {
        _iu.pause.state = 0;
        return 0;
    }
    if ( _demo->input.key_press[KEY_ENTER])
        return 0;
    if (_demo->input.key_press[KEY_ARROW_DOWN] && _iu.pause.state < 5) {
        _iu.pause.state++;
        pause_refresh_str_scaling();
    }
    if (_demo->input.key_press[KEY_ARROW_UP] && _iu.pause.state > 1) {
        _iu.pause.state--;
        pause_refresh_str_scaling();
    }
    return 1;
}