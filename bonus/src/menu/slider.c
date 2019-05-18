/*
** EPITECH PROJECT, 2019
** undefined
** File description:
** slider
*/

#include "headers.h"

static void move_slider(demo_t *demo, entity2_t *slider)
{
    (void)demo;
    (void)slider;
    /*vec2 screen = {demo->win.w , demo->win.h};
    vec2 mouse_posf = {demo->mouse.mouse_pos.x, demo->mouse.mouse_pos.y};
    vec2 relative_mouse_pos;

    relative_mouse_pos = vec2_muls(
    vec2_subs(vec2_div(mouse_posf, screen), 0.5f), 2.0f);
    relative_mouse_pos.y *= -1.0;
    slider->rect.p.x += (relative_mouse_pos.x - slider->rect.p.x);*/
}

static int check_slider_side(entity2_t *slider)
{
    slider->slider->rect.p.x = CLAMP(slider->slider->rect.p.x,
    slider->x_min, slider->x_max);
    return 1;
}

float setting_slider_move(entity2_t *slider)
{
    float segment_len;
    float segment_len2;

    move_slider(_demo, slider->slider);
    check_slider_side(slider);
    segment_len = (slider->x_max - slider->x_min);
    segment_len2 = (slider->slider->rect.p.x - slider->x_min);
    segment_len *= 100;
    segment_len2 *= 100;
    return (segment_len2 / segment_len);
}
