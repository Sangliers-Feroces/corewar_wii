/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** vg_text_constructor
*/

#include "headers.h"

void iu_set_vg_text(void)
{
    char buff[10];

    sprintf(buff, "%d FPS", _demo->win.fps_to_display);
    _iu.data.fps_display = vg_text_create(buff, NULL);
    vg_text_set_position(&_iu.data.fps_display, (vec2){0.80, -0.95});
    vg_text_set_size(&_iu.data.fps_display, (vec2){0.03f, 0.03f});
}