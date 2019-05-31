/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** swaggy demo
*/

#include "headers.h"

void render_delay_call(render_call_t to_draw)
{
    vec_render_call_add(&_demo->buf.to_draw, to_draw);
}

void render_delay_exec(void)
{
    vec_render_call_flush(&_demo->buf.to_draw);
}
