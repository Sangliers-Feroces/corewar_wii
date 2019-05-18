/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** iu_draw
*/

#include "headers.h"

static void vec_msg_update(vec_msg_entry_t *vec)
{
    for (size_t i = 0; i < vec->count; i++)
        if (vec->msg[i].life < _demo->clocks.t) {
            vec_msg_entry_delete(vec, i);
            i--;
        }
}

static double get_x_off(double start, double life)
{
    if (fabs(start - _demo->clocks.t) < 0.3)
        return 1.0 - fabs(start - _demo->clocks.t) / 0.3;
    if (fabs(life - _demo->clocks.t) < 0.3)
        return 1.0 - fabs(life - _demo->clocks.t) / 0.3;
    return 0.0;
}

void vec_msg_display(vec_msg_entry_t *vec)
{
    vg_text text = vg_text_create(NULL, NULL);
    double p = 0.75;

    vec_msg_update(vec);
    for (size_t i = 0; i < vec->count; i++) {
        vg_text_reset_str(&text, vec->msg[i].to_display, NULL);
        vg_text_set_position(&text,
        (vec2){-0.95 - get_x_off(vec->msg[i].start, vec->msg[i].life), p});
        vg_text_draw(text);
        p -= 0.1;
    }
}

void msg_add(char *msg, double duration)
{
    vec_msg_entry_add(&_demo->buf.msgs,
    msg_entry_create(msg, _demo->clocks.t, _demo->clocks.t + duration));
}
